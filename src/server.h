/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file server.h Declarations of the server type */

#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <vector>
#include <memory>

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
	std::vector<std::unique_ptr<QTcpSocket>> clients;
};

#endif /* SERVER_H */
