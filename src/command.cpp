/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
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

	/* Put the first 8 bytes of rawdata into the respective 4 byte ints. */
	rawdata >> type_int >> meta_len;

	qDebug() << "Command:" << type_int;
	qDebug() << "Meta length:" << meta_len;

	CommandType type = static_cast<CommandType>(type_int);
	if (type >= CommandType::COUNT) {
		qDebug() << "Invalid command";
		/* Abort */
		Command cmd(CommandType::INVALID, "");
		return cmd;
	}

	QByteArray meta;
	meta.resize(meta_len);
	if (rawdata.readRawData(meta.data(), meta_len) != meta_len) {
		qDebug() << "Invalid read length";
		/* Abort */
		Command cmd(CommandType::INVALID, "");
		return cmd;
	}

	qDebug() << "Meta" << meta;

	Command cmd(type, meta);
	return cmd;
}

/**
 * Instance Method.
 * Checks if the command is valid.
 * @return True if the command is valid. False otherwise.
 */
bool Command::IsValid()
{
	return this->cmdtype < CommandType::COUNT;
}
