#include "player.h"

#include <stdbool.h>

#include "../game.h"
#include "../sprite/sprite.h"

extern int window_width;

player_t* player_create(game_t* game, vec2i_t start_position) {
    player_t* player = malloc(sizeof(player_t));

    player->game = game;
    player->position = start_position;
    player->sprite = sprite_create(game->renderer, "assets/img/player-sprite.png", true, false, (vec2i_t) {16, 16}, 0, (vec2i_t) {0, 2});

    player->sprite->position = start_position;

    player->sprite->scale_factor = 5;
    player->sprite->update_each_nth_frame = 10;

    return player;
}

void player_update(player_t* player) {
    sprite_update(player->sprite);
}

void player_render(const player_t* player) {
    sprite_render(player->sprite);
}

void player_keyboard_input(player_t* player, const Uint8* const keyboard_state) {
}