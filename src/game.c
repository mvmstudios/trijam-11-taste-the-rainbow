#include "game.h"

#include "player/player.h"
#include "hitbox/hitbox.h"
#include "sprite/sprite.h"
#include "floor/floor.h"
#include "skittle/skittle.h"

bool debug = false;

floor_t* _floor;
skittle_t* skittles[1028];

int current_skittle_index = 0;

extern int window_width;
extern int window_height;

typedef struct SkittleDropper {
    game_t* game;

    vec2i_t velocity;
    hitbox_t* hitbox;
} skittle_dropper_t;

skittle_dropper_t* skittle_dropper_create(game_t* game, vec2i_t init_pos) {
    skittle_dropper_t* dropper = malloc(sizeof(skittle_dropper_t));

    dropper->velocity = (vec2i_t) { 10, 0 };
    dropper->game = game;
    dropper->hitbox = hitbox_create(init_pos.x, init_pos.y, 10, 10);

    return dropper;
}

void skittle_dropper_update(skittle_dropper_t* dropper) {
    dropper->hitbox->x += dropper->velocity.x;

    if (dropper->hitbox->x > window_width - dropper->hitbox->width) {
        dropper->hitbox->x = window_width - dropper->hitbox->width;
        dropper->velocity.x = -dropper->velocity.x;
    }

    if (dropper->hitbox->x < 0) {
        dropper->hitbox->x = 0;
        dropper->velocity.x = -dropper->velocity.x;
    }

}

void skittle_dropper_render(skittle_dropper_t* dropper) {
    if (debug)
        hitbox_render(dropper->hitbox, dropper->game->renderer);
}

skittle_dropper_t* skittle_dropper;

game_t* game_create(SDL_Renderer* renderer) {
    game_t* game = malloc(sizeof(game_t));

    game->renderer = renderer;
    game->player = player_create(game, (vec2i_t) {0, 0});

    _floor = floor_create(game);
    skittle_dropper = skittle_dropper_create(game, (vec2i_t) {0, 0});

    return game;
}

void game_update(game_t* game, const float delta_time, const float global_time, const uint64_t frame_count) {
    player_update(game->player);
    floor_update(_floor);

    skittle_dropper_update(skittle_dropper);

    // i don't like this!
    //if (frame_count % 200 == 0 && current_skittle_index <= 128 - 2)
        //skittles[current_skittle_index++] = skittle_create(game, (vec2i_t) {0, 10});

    //for (int i = 0; i < current_skittle_index; i++)
       // skittle_update(skittles[i], global_time);
}

void game_render(const game_t* game) {
    SDL_SetRenderDrawColor(game->renderer, 137, 229, 255, 255);
    SDL_RenderClear(game->renderer);
    player_render(game->player);
    floor_render(_floor);


    skittle_dropper_render(skittle_dropper);

   // for (int i = 0; i < current_skittle_index; i++)
       // skittle_render(skittles[i]);
}

void game_event(game_t* game, const SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_O)
            debug = !debug;
    }
}

void game_keyboard_input(game_t* game, const Uint8* const keyboard_state) {
    player_keyboard_input(game->player, keyboard_state);
}