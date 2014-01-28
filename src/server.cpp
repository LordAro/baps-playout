/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file server.cpp Implementation of the server type */

#include "util.h"
#include "command_handler.h"
#include "command_router.h"
#include "command_handlers/version.h"
#include "server.h"

BAPSServer::BAPSServer(QObject *parent)
	: QTcpServer(parent)
{
	/* Create an instance of the Command Router and then register each
	 * command handler */
	this->cmdRouter = CommandRouter();
	this->cmdRouter.Register(CommandHandlerPtr(new VersionHandler()));
}



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

	std::string cmdstr = ReadCommandLine(client);
	CommandHandlerPtr cmd = this->cmdRouter.DecodeCommand(cmdstr);
	ProcessCommand(cmd, cmdstr, client);
}

/**
 * A client/socket disconnected.
 * @todo Inform other connected people on disconnect?
 */
void BAPSServer::Disconnected()
{
	auto client = static_cast<QTcpSocket *>(sender());
	assert(client != nullptr);

	for (auto elem = this->clients.begin(); elem != this->clients.end(); ++elem) {
		if (client == elem->get()) {
			qDebug() << "Removing:" << client->peerAddress().toString();
			this->clients.erase(elem);
			return;
		}
	}
	qWarning() << "Unable to remove client:" << client->peerAddress().toString();
}

/**
 * Read a command line from a client socket.
 * @param client The client whose command line is to be read.
 * @return The string representing the command line read from the client.
 * @note This is a blocking operation.
 */
std::string BAPSServer::ReadCommandLine(QTcpSocket *client)
{
	QByteArray bytes = client->readLine(0);
	return QString(bytes).trimmed().toStdString();
}

/**
 * Process a command, given its handler, command line and the client that sent it.
 * @param cmd A pointer to the command handler responsible for processing this command.
 * @param cmdstr The full command string.
 * @param client The client whose command is being processed.
 * @todo Pass the command a parsed form of the command string (eg, vector of arguments)?
 */
void BAPSServer::ProcessCommand(CommandHandlerPtr cmd, std::string cmdstr, QTcpSocket *client)
{
	if (cmd == nullptr) {
		qWarning() << "Cannot process invalid command";
		return;
	}

	cmd->HandleEvent(cmdstr, client);
}
