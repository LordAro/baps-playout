/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file server.cpp Implementation of the server type */

#include "util.h"
#include "command.h"
#include "server.h"

BAPSServer::BAPSServer(QObject *parent)
	: QTcpServer(parent) {}

void BAPSServer::incomingConnection(qintptr socket_desc)
{
	auto client = std::unique_ptr<QTcpSocket>(new QTcpSocket());
	client->setSocketDescriptor(socket_desc);

	qDebug() << "New client from:" << client->peerAddress().toString();

	/* Connect client to signals */
	connect(client.get(), SIGNAL(readyRead()), this, SLOT(ReadTCPData()));
	connect(client.get(), SIGNAL(disconnected()), this, SLOT(Disconnected()));

	this->clients.push_back(std::move(client));
}

/**
 * Get a command from a client.
 * @todo Implement properly.
 */
void BAPSServer::ReadTCPData()
{
	auto client = static_cast<QTcpSocket *>(sender());
	assert(client != nullptr);

	if (client->bytesAvailable() < (int)sizeof(CommandType) + (int)sizeof(int)) {
		qWarning() << "Malformed packet";
		return;
	}
	QDataStream raw(client);

	Command cmd = DecodeCommand(raw);

	/* Process command */
	if (!cmd.IsValid()) {
		qWarning() << "Cannot process invalid command";
		return;
	}
}

/**
 * A client/socket disconnected.
 * @todo Inform other connected people on disconnect?
 */
void BAPSServer::Disconnected()
{
	auto client = static_cast<QTcpSocket *>(sender());
	assert(client != nullptr);

	auto rm_elem = std::remove_if(this->clients.begin(), this->clients.end(),
	                              [client](std::unique_ptr<QTcpSocket> const &c) { return c.get() == client; });
	if (rm_elem != this->clients.end()) {
		qDebug() << "Removing:" << client->peerAddress().toString();
		this->clients.erase(rm_elem);
	} else {
		qWarning() << "Unable to remove client:" << client->peerAddress().toString();
	}
}
