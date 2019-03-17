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

    skittle->game = game;

    skittle->disabled = false;
    skittle->position = init_pos;
    
    skittle->sprite = sprite_create(game->renderer, "assets/img/skittle-sprite.png", false, false, (vec2i_t) {9, 4}, 0, (vec2i_t) {0, 0});

    skittle->sprite->position = init_pos;

    skittle->sprite->size.x = 9 * 3;
    skittle->sprite->size.y = 4 * 3;

    skittle->hitbox = hitbox_create(skittle->position.x, skittle->position.y, skittle->sprite->size.x, skittle->sprite->size.y);

    return skittle;
}

void skittle_update(skittle_t* skittle, float global_time) {
    if (skittle->disabled)
        return;

    if (!hitbox_collide(skittle->hitbox, _floor->hitbox)) {
        skittle->position.y += 2;
    }

    if (hitbox_collide(skittle->hitbox, skittle->game->player->hitbox))
        player_eat_skittle(skittle->game->player, skittle);

    skittle->hitbox->y = skittle->position.y;
    skittle->sprite->position.y = skittle->position.y;
}

void skittle_render(skittle_t* skittle) {
    if (skittle->disabled)
        return;

    sprite_render(skittle->sprite);
    if (debug)
        hitbox_render_colored(skittle->hitbox, skittle->game->renderer, (vec4i_t) {255, 114, 247, 255}, (vec4i_t) { 119, 99, 249, 100 });
}