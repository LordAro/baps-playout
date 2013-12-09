/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file baps.cpp Functions related to starting BAPS. */

#include "server.h"

#include <QtCore>

/**
 * Main entry point for this lovely program.
 * @param argc Number of arguments passed to this game.
 * @param argv Values of the arguments.
 * @return 0 when there is no error.
 */
int main(int argc, char **argv)
{
	QCoreApplication a(argc, argv);
	auto server = std::unique_ptr<BAPSServer>(new BAPSServer());
	
	if (!server->listen(QHostAddress::Any, 1350)) {
		qFatal("Error starting TcpSever: %s", qPrintable(server->errorString()));
	}

	qDebug() << "Listening on:" << server->serverAddress().toString()
	         << ':' << server->serverPort();
	return a.exec();
}
