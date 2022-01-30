///////////////////////////////////////////////////////////////////////////////
// NAME:            game-list.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Implementation of the game list iterator.
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

#include <stdlib.h>
#include <string.h>

#include <rom-runner/game-list.h>

typedef struct GameList {
    size_t index;
} GameList;

static struct GameListEntry GAME_LIST[] = {
    { .name="Game One" },
    { .name="Game Two" },
    { 0 },
};

///////////////////////////////////////////////////////////////////////////////
// Public API
////

GameList* game_list_iter_new() {
    GameList* iter = malloc(sizeof(GameList));
    memset(iter, 0, sizeof(GameList));
    return iter;
}

void game_list_iter_free(GameList* iter)
{ free(iter); }

GameListEntry* game_list_iter_next(GameList* iter) {
    if (NULL == GAME_LIST[iter->index].name) {
        return NULL;
    }

    return &GAME_LIST[iter->index++];
}

///////////////////////////////////////////////////////////////////////////////
