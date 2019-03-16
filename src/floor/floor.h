#ifndef FLOOR_H_
#define FLOOR_H_

#include <stdlib.h>

#include "../game.h"
#include "../hitbox/hitbox.h"
#include "../sprite/sprite.h"
#include "../math/mvmath.h"

typedef struct Floor {
    game_t* game;

    vec2i_t position;

    sprite_t* floor_sprite;
    hitbox_t* hitbox;
} floor_t;

floor_t* floor_create(game_t* game);

void floor_update(floor_t* floor);

void floor_render(floor_t* floor);

#endif