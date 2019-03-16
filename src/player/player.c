#include "player.h"

#include <stdbool.h>

#include "../game.h"
#include "../sprite/sprite.h"

extern int window_width;
extern bool debug;

player_t* player_create(game_t* game, vec2i_t start_position) {
    player_t* player = malloc(sizeof(player_t));

    player->game = game;
    player->position = start_position;
    player->sprite = sprite_create(game->renderer, "assets/img/player-sprite.png", true, false, (vec2i_t) {16, 16}, 0, (vec2i_t) {0, 2});

    player->sprite->position = start_position;

   // player->sprite->size = (vec2i_t) { window_width * 0.20, window_width * 0.2 };
    player->sprite->update_each_nth_frame = 10;

    player->hitbox = hitbox_create(player->position.x, player->position.y, player->sprite->size.x, player->sprite->size.y);

    return player;
}

void player_update(player_t* player) {
    player->sprite->size = (vec2i_t) { window_width * 0.10, window_width * 0.10 };
    player->hitbox->x = player->position.x;
    player->hitbox->y = player->position.y;

    player->hitbox->width = player->sprite->size.x;
    player->hitbox->height = player->sprite->size.y;

    sprite_update(player->sprite);
}

void player_render(const player_t* player) {
    sprite_render(player->sprite);
    if (debug)
        hitbox_render(player->hitbox, player->game->renderer);
}

void player_keyboard_input(player_t* player, const Uint8* const keyboard_state) {
}