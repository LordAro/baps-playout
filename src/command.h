/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file command.h Declarations of command related types. */

#ifndef COMMAND_H
#define COMMAND_H

#include <QDataStream>
#include <QString>

/** Define all command types. */
enum class CommandType {
	TEMP,    ///< \todo Remove.
	COUNT,   ///< Number of commands.
	INVALID, ///< Invalid command.
};

/** Command */
class Command {
public:
	Command(CommandType cmdtype, QString metadata);

	CommandType cmdtype; ///< Type of the command.
	QString metadata;    ///< Metadata accompanying the command.
};

Command DecodeCommand(QDataStream &rawdata);

#endif /* COMMAND_H */