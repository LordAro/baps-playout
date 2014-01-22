/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file command_router.cpp Implementation of CommandRouter class. */

#include "util.h"
#include "command_router.h"

CommandRouter::CommandRouter() {}

/**
 * Register a Command Handler.
 * @param pointer to the CommandHandler instance
 * @return Bool with success or failure
 * @todo Pick the string out of the instance to use as the map key
 */
bool CommandRouter::Register(CommandHandler *handler)
{
	if (NULL != handler)
	{
		/* Fish the command type from the child instance */
		commandHandlers[handler->cmdtype] = handler;
		return true;
	} else {
		return false;
	}
}

/**
 * Decode a datastream from a client.
 * @param rawdata Reference to client's data stream.
 * @return Appropriate Command Handler child class instance
 */
CommandHandler *CommandRouter::DecodeCommand(QString &cmdStr)
{
	/* Decode the string and return an appropriate commandhandler child, or
         * return null if it's an invalid command */
	
	qDebug() << cmdStr;

	return nullptr;
}
