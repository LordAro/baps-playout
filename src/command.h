/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
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

	bool IsValid();
};

Command DecodeCommand(QDataStream &rawdata);

#endif /* COMMAND_H */
