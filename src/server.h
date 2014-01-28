/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file server.h Declarations of the server type */

#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSharedPointer>
#include <vector>
#include <memory>
#include <command_router.h>

/** Main server instance. */
class BAPSServer : public QTcpServer {
	Q_OBJECT

public:
	BAPSServer(QObject *parent = nullptr);

private slots:
	void ReadTCPData();
	void Disconnected();
protected:
	void incomingConnection(qintptr socket_desc) override;
private:
	std::vector<QSharedPointer<QTcpSocket>> clients;
	CommandRouter cmdRouter;

	std::string ReadCommandLine(QTcpSocket *client);
	void ProcessCommand(CommandHandlerPtr cmd, std::string cmdstr, QTcpSocket *client);
};

#endif /* SERVER_H */
