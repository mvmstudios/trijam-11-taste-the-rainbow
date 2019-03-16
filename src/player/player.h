#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdlib.h>

#include "../math/mvmath.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"

typedef struct Game game_t;

typedef enum PlayerFacing {
    PLAYER_FACING_LEFT,
    PLAYER_FACING_RIGHT,
    PLAYER_FACING_UP
} player_facing_t;

typedef struct Player {
    game_t* game;

    vec2i_t position;

    player_facing_t facing;

    sprite_t* sprite;
    hitbox_t* hitbox;
} player_t;

player_t* player_create(game_t* game, vec2i_t start_position);
// void player_destroy();

void player_update(player_t* player);
void player_render(const player_t* player);

void player_keyboard_input(player_t* player, const Uint8* const keyboard_state);

void player_move_to(player_t* player, vec2i_t position);

#endif