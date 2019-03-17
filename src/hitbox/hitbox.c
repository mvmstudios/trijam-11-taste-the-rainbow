#include "hitbox.h"

#include <SDL2/SDL.h>

hitbox_t* hitbox_create(int x, int y, int width, int height) {
    hitbox_t* hitbox = malloc(sizeof(hitbox_t));

    hitbox->x = x;
    hitbox->y = y;
    hitbox->width = width;
    hitbox->height = height;

    return hitbox;
}

bool hitbox_collide(hitbox_t* hitbox_1, hitbox_t* hitbox_2) {
    hitbox_t* x_min_hitbox = hitbox_1->x < hitbox_2->x ? hitbox_1 : hitbox_2;
    hitbox_t* x_max_hitbox = hitbox_1->x > hitbox_2->x ? hitbox_1 : hitbox_2;

    hitbox_t* y_min_hitbox = hitbox_1->y < hitbox_2->y ? hitbox_1 : hitbox_2;
    hitbox_t* y_max_hitbox = hitbox_1->y > hitbox_2->y ? hitbox_1 : hitbox_2;

    if (x_min_hitbox->x + x_min_hitbox->width > x_max_hitbox->x) {
        if (y_min_hitbox->y + y_max_hitbox->height > y_max_hitbox->y) {
            return true;
        }
    }

    return false;
}

void hitbox_render(hitbox_t* hitbox, SDL_Renderer* renderer) {
    SDL_Rect rect = {hitbox->x, hitbox->y, hitbox->width, hitbox->height};

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 150, 255, 150, 100);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}