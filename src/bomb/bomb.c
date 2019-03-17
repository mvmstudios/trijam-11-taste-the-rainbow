#include "bomb.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL_mixer.h>

#include "../game.h"

#include "../math/mvmath.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"
#include "../floor/floor.h"

extern floor_t* _floor;
extern bool debug;

extern Mix_Chunk* explode_effect_sound;

bomb_t* bomb_create(game_t* game, vec2i_t init_pos) {
    bomb_t* bomb = malloc(sizeof(bomb_t));

    bomb->game = game;

    bomb->disabled = false;
    bomb->position = init_pos;
    
    bomb->sprite = sprite_create(game->renderer, "assets/img/bomb-sprite.png", false, false, (vec2i_t) {16, 16}, 0, (vec2i_t) {0, 0});

    bomb->sprite->position = init_pos;
    

    bomb->sprite->size.x = 16 * 2;
    bomb->sprite->size.y = 16 * 2;

    bomb->hitbox = hitbox_create(bomb->position.x, bomb->position.y, bomb->sprite->size.x, bomb->sprite->size.y);

    return bomb;
}

void bomb_update(bomb_t* bomb, float global_time) {
    if (bomb->disabled)
        return;

    if (bomb->bomb_state == BOMB_STATE_EXPLODING) {
        if (global_time - bomb->exploded_at_time > 1)
            bomb->disabled = true;
        return;
    }

    if (!hitbox_collide(bomb->hitbox, _floor->hitbox) && !hitbox_collide(bomb->hitbox, bomb->game->player->hitbox)) {
        bomb->position.y += 3.5;
    } else {
        bomb_explode(bomb);
    }

    printf("%f\n", global_time);

    bomb->hitbox->y = bomb->position.y;
    bomb->sprite->position.y = bomb->position.y;
}

void bomb_render(bomb_t* bomb) {
    if (!bomb->disabled) {
        sprite_render(bomb->sprite);
        if (debug)
            hitbox_render(bomb->hitbox, bomb->game->renderer);
    }
}

void bomb_explode(bomb_t* bomb) {
    Mix_PlayChannel(-1, explode_effect_sound, 0);

    bomb->bomb_state = BOMB_STATE_EXPLODING;
    bomb->sprite->current_sprite_index = 1;

    player_damage(bomb->game->player, 1);
}