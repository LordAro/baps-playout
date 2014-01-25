/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file command_handler.h Declarations of CommandHandler. */

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "util.h"
#include <QTcpSocket>

class CommandHandler {
public:
	CommandHandler(const std::string &cmdtype);

	virtual void HandleEvent(std::string payload, QTcpSocket *clientSocket) = 0;

	const std::string cmdtype; ///< Type of the Command.
};

typedef std::shared_ptr<CommandHandler> CommandHandlerPtr;

#endif /* COMMAND_HANDLER_H */
