/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
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
