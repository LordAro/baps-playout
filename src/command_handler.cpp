/*
 * This file is part of BAPS.
 * BAPS is licenced under MIT License. See LICENSE.txt for more details.
 */

/** @file command_handler.cpp Definitions of CommandHandler. */

#include "command_handler.h"

/**
 * Constructor.
 * @param cmdtype The type of the command.
 */
CommandHandler::CommandHandler(const std::string &cmdtype) : cmdtype(cmdtype) {}

