///////////////////////////////////////////////////////////////////////////////
// NAME:            game-list.h
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Routines for getting the list of games from the server?
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

#ifndef ROM_TORTUGA_GAME_LIST_H
#define ROM_TORTUGA_GAME_LIST_H

typedef struct GameList GameList;

typedef struct GameListEntry {
    const char* name;
} GameListEntry;

GameList* game_list_iter_new();
void game_list_iter_free(GameList* iter);

GameListEntry* game_list_iter_next(GameList* iter);

#endif // ROM_TORTUGA_GAME_LIST_H

///////////////////////////////////////////////////////////////////////////////
