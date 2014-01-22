/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file command_router.h Routes commands to their appropriate handler */

#ifndef COMMAND_ROUTER_H
#define COMMAND_ROUTER_H

#include <QString>
#include <map>

#include <command_handler.h>

/** CommandRouter */
class CommandRouter {
public:
	CommandRouter();

	bool Register(CommandHandler *handler); ///< Register a CommandHandler
	CommandHandler *DecodeCommand(QString &cmdStr);

private:
	// Lookup table to map command to command handler
	std::map<QString, CommandHandler *> commandHandlers;
	
};

#endif /* COMMAND_ROUTER_H */
