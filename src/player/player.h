#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdlib.h>

#include "../game.h"
#include "../math/mvmath.h"
#include "../sprite/sprite.h"

typedef struct Player {
    game_t* game;

    vec2i_t position;

    sprite_t* sprite;
} player_t;

player_t* player_create(game_t* game, vec2i_t start_position);
// void player_destroy();

void player_update(player_t* player);
void player_render(const player_t* player);

void player_keyboard_input(player_t* player, const Uint8* const keyboard_state);

#endif