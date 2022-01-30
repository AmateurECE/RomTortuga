///////////////////////////////////////////////////////////////////////////////
// NAME:            main.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Top level script.
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

#include <assert.h>
#include <gtk/gtk.h>
#include <glib/gstdio.h>

#include <rom-runner/game-list.h>

static void populate_sidebar(GtkStack* stack) {
    GameList* iter = game_list_iter_new();
    GameListEntry* entry = NULL;
    while (NULL != (entry = game_list_iter_next(iter))) {
        GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_stack_add_titled(GTK_STACK(stack), box, entry->name, entry->name);
    }
    game_list_iter_free(iter);
}

static void activate(GtkApplication* app, gpointer user_data) {
    GtkBuilder* builder = gtk_builder_new();
    const char* builder_path = getenv("GTK_BUILDER_PATH");
    assert(NULL != builder_path);
    gtk_builder_add_from_file(builder, builder_path, NULL);

    GObject* window = gtk_builder_get_object(builder, "window");
    gtk_window_set_application(GTK_WINDOW(window), app);

    GtkWidget* stack = gtk_stack_new();
    populate_sidebar(GTK_STACK(stack));

    GObject* stack_sidebar = gtk_builder_get_object(builder, "sidebar");
    gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(stack_sidebar),
        GTK_STACK(stack));

    gtk_widget_show(GTK_WIDGET(window));
    g_object_unref(builder);
}

int main(int argc, char** argv) {
#ifdef GTK_SRCDIR
    g_chdir(GTK_SRCDIR);
#endif

    GtkApplication* app = gtk_application_new("org.edtwardy.rom-runner",
        G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

///////////////////////////////////////////////////////////////////////////////
