/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file command.cpp Implementations of command related types. */

#include "util.h"
#include "command.h"

Command::Command(CommandType cmdtype, QString metadata)
	: cmdtype(cmdtype), metadata(metadata) {}

/**
 * Decode a datastream from a client.
 * @param rawdata Reference to client's data stream.
 * @return Decoded command, if non-null.
 * @todo More error checking.
 */
Command DecodeCommand(QDataStream &rawdata)
{
	qint32 type_int;
	qint32 meta_len;
	rawdata >> type_int >> meta_len;

	qDebug() << "Command:" << type_int;
	qDebug() << "Meta length:" << meta_len;

	CommandType type = static_cast<CommandType>(type_int);
	if (type >= CommandType::COUNT) {
		qDebug() << "Invalid command";
		/* abort? */
	}

	QByteArray meta;
	meta.resize(meta_len);
	if (rawdata.readRawData(meta.data(), meta_len) != meta_len) {
		qDebug() << "Invalid read length";
		/* abort? */
	}

	qDebug() << "Meta" << meta;

	Command cmd(type, meta);
	return cmd;
}