///////////////////////////////////////////////////////////////////////////////
// NAME:            rom-runner-app-window.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     RomRunner Application Window class implementation.
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

#include <rom-runner/game-list.h>
#include <rom-runner/rom-runner-app.h>
#include <rom-runner/rom-runner-app-window.h>

struct _RomRunnerAppWindow {
    GtkApplicationWindow parent;
    GtkStackSidebar* sidebar;
};

G_DEFINE_TYPE(RomRunnerAppWindow, rom_runner_app_window,
    GTK_TYPE_APPLICATION_WINDOW);

static void rom_runner_app_window_load_games(RomRunnerAppWindow* window) {
    GtkWidget* stack = gtk_stack_new();
    GameList* iter = game_list_iter_new();
    GameListEntry* entry = NULL;
    while (NULL != (entry = game_list_iter_next(iter))) {
        GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_stack_add_titled(GTK_STACK(stack), box, entry->name, entry->name);
    }
    game_list_iter_free(iter);
    gtk_stack_sidebar_set_stack(window->sidebar, GTK_STACK(stack));
}

static void rom_runner_app_window_init(RomRunnerAppWindow* win) {
    gtk_widget_init_template(GTK_WIDGET(win));
    rom_runner_app_window_load_games(win);
}

static void rom_runner_app_window_class_init(RomRunnerAppWindowClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
        "/org/edtwardy/rom-runner/window.ui");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class),
        RomRunnerAppWindow, sidebar);
}

RomRunnerAppWindow* rom_runner_app_window_new(RomRunnerApp* app)
{ return g_object_new(ROM_RUNNER_APP_WINDOW_TYPE, "application", app, NULL); }

///////////////////////////////////////////////////////////////////////////////
