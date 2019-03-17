#include "player.h"

#include <stdbool.h>

#include "../game.h"
#include "../skittle/skittle.h"
#include "../sprite/sprite.h"
#include "SDL2/SDL_mixer.h"

extern int window_width;
extern int window_height;

extern bool debug;

Mix_Chunk* pick_up_sound;

player_t* player_create(game_t* game, vec2i_t start_position) {
    player_t* player = malloc(sizeof(player_t));

    player->game = game;
    player->position = start_position;
    player->sprite = sprite_create(game->renderer, "assets/img/player-sprite.png", true, false, (vec2i_t) {16, 16}, 0, (vec2i_t) {0, 2});

    player->sprite->position = start_position;
    player->facing = PLAYER_FACING_RIGHT;

   // player->sprite->size = (vec2i_t) { window_width * 0.20, window_width * 0.2 };
    player->sprite->update_each_nth_frame = 10;

    player->sprite->size = (vec2i_t) { window_width * 0.10, window_width * 0.10 };

    player->hitbox = hitbox_create(player->position.x, player->position.y, player->sprite->size.x - 20, player->sprite->size.y * 0.3 + 10);

    pick_up_sound = Mix_LoadWAV("assets/sound/pick.wav");

    return player;
}

/**
 * floor shit**
 */
void player_update(player_t* player) {
    if (player->position.x > window_width - player->sprite->size.x)
        player->position.x = window_width - player->sprite->size.x;
    if (player->position.x < 0)
        player->position.x = 0;

    player->hitbox->x = player->position.x;
    player->hitbox->y = player->position.y;

    //player->hitbox->width = player->sprite->size.x;
    //player->hitbox->height = player->sprite->size.y;

    if (player->facing != PLAYER_FACING_UP)
        player->sprite->rotated = player->facing != PLAYER_FACING_RIGHT;

    player->position.y = window_height - window_height * 0.18 - player->sprite->size.y;

    player->sprite->position.x = player->position.x;
    player->sprite->position.y = player->position.y;

    //if (!(hitbox_collide()))

    sprite_update(player->sprite);
}

void player_render(const player_t* player) {
    sprite_render(player->sprite);
    if (debug)
        hitbox_render(player->hitbox, player->game->renderer);
}

void player_keyboard_input(player_t* player, const Uint8* const keyboard_state) {
    if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT]) {
        player->facing = PLAYER_FACING_RIGHT;
        player_move_to(player, (vec2i_t) { 4.5, 0}); 
        player->sprite->current_animation_range = (vec2i_t) {0, 2};
    } else if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT]) {
        player->facing = PLAYER_FACING_LEFT;
        player_move_to(player, (vec2i_t) {-4.5, 0}); 
        player->sprite->current_animation_range = (vec2i_t) {0, 2};
    } /*else if (keyboard_state[SDL_SCANCODE_W] || keyboard_state[SDL_SCANCODE_UP]) {
        player->facing = PLAYER_FACING_UP;
        player->sprite->current_animation_range = (vec2i_t) {3, 5};
        player->sprite->current_sprite_index = 3;
    }*/
}

void player_move_to(player_t* player, vec2i_t position) {
    player->position.x += position.x;
    player->position.y += position.y;
}

void player_eat_skittle(player_t* player, skittle_t* skittle) {
    Mix_PlayChannel(-1, pick_up_sound, 0);
    skittle->disabled = true;
    player->score++;

    player->sprite->current_sprite_index = 3;
}