#ifndef SPRITE_H_
#define SPRITE_H_

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../math/mvmath.h"

typedef struct Sprite {
    SDL_Renderer* renderer;
    SDL_Texture* sprite_texture;

    bool play_animation;
    bool rotated;

    vec2i_t size;
    int update_each_nth_frame;

    vec2i_t position;

    vec2i_t sprite_dimension;
    int current_sprite_index;
    vec2i_t current_animation_range;
} sprite_t;

sprite_t* sprite_create(SDL_Renderer* renderer, const char* path_to_sprite, bool play_animation, bool rotated, vec2i_t dimension, int start_index, vec2i_t animation_range);

void sprite_destroy(sprite_t* sprite);

void sprite_update(sprite_t* sprite);

void sprite_render(const sprite_t* sprite);

#endif