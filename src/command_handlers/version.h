/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file version.h The version CommandHandler. */

#ifndef VERSION_HANDLER_H
#define VERSION_HANDLER_H

#include <QTcpSocket>
#include "../command_handler.h"

class VersionHandler : public CommandHandler {
public:
	VersionHandler();

	void HandleEvent(std::string payload, QTcpSocket *clientSocket) override;
};

#endif /* VERSION_HANDLER_H */
