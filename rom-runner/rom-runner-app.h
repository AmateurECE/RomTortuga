///////////////////////////////////////////////////////////////////////////////
// NAME:            rom-runner-app.h
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     GtkApplication subclass for RomRunner.
//
// CREATED:         01/30/2022
//
// LAST EDITED:     01/30/2022
//
// Copyright 2022, Ethan D. Twardy
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////

#ifndef ROM_RUNNER_APP_H
#define ROM_RUNNER_APP_H

#include <gtk/gtk.h>

#define ROM_RUNNER_APP_TYPE (rom_runner_app_get_type())
G_DECLARE_FINAL_TYPE(RomRunnerApp, rom_runner_app, ROM_RUNNER, APP,
    GtkApplication);

RomRunnerApp* rom_runner_app_new();

#endif // ROM_RUNNER_APP_H

///////////////////////////////////////////////////////////////////////////////
