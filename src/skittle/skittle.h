#ifndef SKITTLE_H_
#define SKITTLE_H_

#include "../math/mvmath.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"

typedef struct Skittle {
    vec2i_t position;

    sprite_t sprite;
    hitbox_t hitbox;
} skittle_t;

skittle_t* skittle_create();

void skittle_update(skittle_t* skittle, float global_time);

void skittle_render(skittle_t* skittle);

#endif