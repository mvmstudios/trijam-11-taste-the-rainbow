#ifndef BOMB_H_
#define BOMB_H_

#include "../math/mvmath.h"

#include <stdbool.h>

#include "../game.h"
#include "../math/mvmath.h"
#include "../sprite/sprite.h"
#include "../hitbox/hitbox.h"

typedef enum BombState {
    BOMB_STATE_FALLING,
    BOMB_STATE_EXPLODING
} bomb_state_t;

typedef struct Bomb {
    game_t* game;

    bomb_state_t bomb_state;
    float exploded_at_time;
    bool disabled;

    vec2i_t position;

    sprite_t* sprite;
    hitbox_t* hitbox;
} bomb_t;

bomb_t* bomb_create(game_t* game, vec2i_t init_pos);

void bomb_update(bomb_t* bomb, float global_time);

void bomb_render(bomb_t* bomb);

void bomb_explode(bomb_t* bomb);

void bomb_mouse_event(bomb_t* bomb, SDL_MouseButtonEvent event);

#endif