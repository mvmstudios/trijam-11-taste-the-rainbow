#include "sprite.h"

#include <stdbool.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../math/mvmath.h"

extern uint64_t frame_count;

sprite_t* sprite_create(SDL_Renderer* renderer, const char* path_to_sprite, bool play_animation, bool rotated, vec2i_t dimension, int start_index, vec2i_t animation_range) {
    sprite_t* sprite = malloc(sizeof(sprite_t));

    sprite->renderer = renderer;

    SDL_Surface* sprite_surface = IMG_Load(path_to_sprite);

    sprite->sprite_texture = SDL_CreateTextureFromSurface(renderer, sprite_surface);

    SDL_FreeSurface(sprite_surface);

    sprite->play_animation = play_animation;
    sprite->rotated = rotated;
    sprite->scale_factor = 1.0;
    sprite->position = (vec2i_t) { 0, 0 };
    sprite->dimension = dimension;
    sprite->current_sprite_index = start_index;
    sprite->current_animation_range = animation_range;

    sprite->update_each_nth_frame = 5;

    return sprite;
}

void sprite_update(sprite_t* sprite) {
    if (!(sprite->play_animation))
        return;

    if (!(frame_count % sprite->update_each_nth_frame == 0))
        return;

    sprite->current_sprite_index++;
    if (sprite->current_sprite_index > sprite->current_animation_range.y)
        sprite->current_sprite_index = sprite->current_animation_range.x;
}

void sprite_render(const sprite_t* sprite) {
    SDL_Rect src_rect = { sprite->dimension.x * sprite->current_sprite_index, 0, sprite->dimension.x, sprite->dimension.y };
    SDL_Rect dest_rect = { sprite->position.x, sprite->position.y, (float) sprite->dimension.x * sprite->scale_factor, (float) sprite->dimension.y * sprite->scale_factor };
    
    SDL_RenderCopyEx(sprite->renderer, sprite->sprite_texture, &src_rect, &dest_rect, 0, NULL, sprite->rotated);
}