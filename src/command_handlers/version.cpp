/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file version.cpp Implementation of VersionHandler class. */

#include "version.h"
#include "../command_handler.h"

VersionHandler::VersionHandler() : CommandHandler("VERSION") {}

void VersionHandler::HandleEvent(std::string payload, QTcpSocket *clientSocket)
{
	clientSocket->write("BAPS PLAYOUT VERSION 0.01\n");
}
