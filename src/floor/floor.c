#include "floor.h"

#include "../game.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"

extern int window_width;
extern int window_height;
extern bool debug;

floor_t* floor_create(game_t* game) {
    floor_t* _floor = malloc(sizeof(floor_t));

    _floor->game = game;
    _floor->floor_sprite = sprite_create(game->renderer, "assets/img/floor.png", false, false, (vec2i_t) { 256, 21 }, 0, (vec2i_t) {0, 0});

    _floor->position.x = 0;

    _floor->floor_sprite->size.x = window_width;
    _floor->floor_sprite->size.y = window_height * 0.10;
    _floor->floor_sprite->position.y = window_height - _floor->floor_sprite->size.y; 

    _floor->hitbox = hitbox_create(1, 1, 1, 1);

    return _floor;
}

void floor_update(floor_t* floor) {
    floor->floor_sprite->size.x = window_width;
    floor->floor_sprite->size.y = window_height * 0.15;
    floor->floor_sprite->position.y = window_height - floor->floor_sprite->size.y; 
}

void floor_render(floor_t* floor) {
    sprite_render(floor->floor_sprite);
}