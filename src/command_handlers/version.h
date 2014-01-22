/*
 * This file is part of BAPS.
 * BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file version.h The version CommandHandler. */

#ifndef VERSION_HANDLER_H
#define VERSION_HANDLER_H

#include "../command_handler.h"
#include <QString>

/** VersionHandler */
class VersionHandler : public CommandHandler {
public:
	VersionHandler();

	QString cmdtype = "VERSION";

	void HandleEvent(QString payload);
};

#endif /* VERSION__HANDLER_H */
