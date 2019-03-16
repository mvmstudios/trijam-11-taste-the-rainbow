#ifndef SPRITE_H_
#define SPRITE_H_

#include <stdbool.h>

#include <SDL2/SDL_image.h>

#include "../math/mvmath.h"

typedef struct Sprite {
    SDL_Texture* sprite_texture;
    

    bool play_animation;

    vec2i_t dimension;

    int current_sprite_index;
    vec2i_t current_animation_range;
} sprite_t;

sprite_t* sprite_create(const char* path_to_sprite, bool play_animation, vec2i_t dimension, int start_index, vec2i_t animation_range);
// void sprite_destroy();

void sprite_update(sprite_t* sprite);

void sprite_render(sprite_t* sprite, vec2i_t position);

#endif