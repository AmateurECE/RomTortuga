///////////////////////////////////////////////////////////////////////////////
// NAME:            rom-runner-app.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Implementation of the RomRunnerApp subclass.
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

#include <gtk/gtk.h>

#include <rom-runner/rom-runner-app.h>
#include <rom-runner/rom-runner-app-window.h>

struct _RomRunnerApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(RomRunnerApp, rom_runner_app, GTK_TYPE_APPLICATION);

static void rom_runner_app_init(RomRunnerApp* app)
{}

static void rom_runner_app_activate(GApplication* app) {
    RomRunnerAppWindow* win = rom_runner_app_window_new(ROM_RUNNER_APP(app));
    gtk_window_present(GTK_WINDOW(win));
}

static void rom_runner_app_class_init(RomRunnerAppClass* class) {
    G_APPLICATION_CLASS(class)->activate = rom_runner_app_activate;
}

RomRunnerApp* rom_runner_app_new() {
    return g_object_new(ROM_RUNNER_APP_TYPE,
        "application-id", "org.edtwardy.rom-runner",
        "flags", G_APPLICATION_FLAGS_NONE,
        NULL);
}

///////////////////////////////////////////////////////////////////////////////
