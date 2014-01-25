/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file command_router.h Routes commands to their appropriate handler */

#ifndef COMMAND_ROUTER_H
#define COMMAND_ROUTER_H

#include <QString>
#include <map>
#include "command_handler.h"

class CommandRouter {
public:
	bool Register(CommandHandlerPtr handler);
	CommandHandlerPtr DecodeCommand(const std::string &cmdStr);

private:
	/** Lookup table to map command to command handler. */
	std::map<std::string, CommandHandlerPtr> commandHandlers;
};

#endif /* COMMAND_ROUTER_H */
