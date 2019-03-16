#include "skittle.h"

#include <stdbool.h>

#include "../game.h"

#include "../math/mvmath.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"
#include "../floor/floor.h"

extern floor_t* _floor;
extern bool debug;

skittle_t* skittle_create(game_t* game, vec2i_t init_pos) {
    skittle_t* skittle = malloc(sizeof(skittle_t));

    skittle->position = init_pos;
    
    skittle->sprite = sprite_create(game->renderer, "assets/img/skittle-sprite.png", false, false, (vec2i_t) {9, 4}, 0, (vec2i_t) {0, 0});
    skittle->hitbox = hitbox_create(init_pos.x, init_pos.y, skittle->sprite->size.x, skittle->sprite->size.y);

    skittle->sprite->position = init_pos;

    return skittle;
}

void skittle_update(skittle_t* skittle, float global_time) {
    if (!hitbox_collide(skittle->hitbox, _floor->hitbox)) {
        skittle->position.y += 2;
    }

    skittle->hitbox->y = skittle->position.y;
    skittle->sprite->position.y = skittle->position.y;
}

void skittle_render(skittle_t* skittle) {
    sprite_render(skittle->sprite);
    if (debug)
        hitbox_render(skittle->hitbox, skittle->game->renderer);
}