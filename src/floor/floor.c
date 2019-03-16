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
    _floor->floor_sprite = sprite_create(game->renderer, "assets/img/floor.png", false, false, vec2i_t);

    return _floor;
}

void floor_update(floor_t* floor) {

}

void floor_render(floor_t* floor) {
    sprite_render(floor->floor_sprite);
}