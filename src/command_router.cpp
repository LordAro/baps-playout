/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file command_router.cpp Implementation of CommandRouter class. */

#include "util.h"
#include "command_router.h"

/**
 * Register a Command Handler.
 * @param handler Pointer to the CommandHandler instance.
 * @return Was registering the CommandHandler successful?
 */
bool CommandRouter::Register(CommandHandlerPtr handler)
{
	if (handler != nullptr) {
		/* Fish the command type from the child instance */
		this->commandHandlers[handler->cmdtype] = handler;
		return true;
	}
	return false;
}

/**
 * Decode a datastream from a client.
 * @param cmdstr A command from a client.
 * @return Appropriate CommandHandler child class instance.
 */
CommandHandlerPtr CommandRouter::DecodeCommand(const std::string &cmdstr)
{
	/* Decode the string and return an appropriate commandhandler
	 * child, or return null if it's an invalid command */
	qDebug() << QString(cmdstr.c_str());

	if (this->commandHandlers.find(cmdstr) != this->commandHandlers.end()) {
		return this->commandHandlers[cmdstr];
	}
	return nullptr;
}
