#ifndef HITBOX_H_
#define HITBOX_H_

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../math/mvmath.h"

typedef struct Hitbox {
    int x;
    int y;
    int width;
    int height;
} hitbox_t;

hitbox_t* hitbox_create(int x, int y, int width, int height);

bool hitbox_collide(hitbox_t* hitbox_1, hitbox_t* hitbox_2);

void hitbox_render_colored(hitbox_t* hitbox, SDL_Renderer* renderer, vec4i_t outline_color, vec4i_t fill_color);

void hitbox_render(hitbox_t* hitbox, SDL_Renderer* renderer);

#endif