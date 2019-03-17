#include "game.h"

#include "player/player.h"
#include "hitbox/hitbox.h"
#include "sprite/sprite.h"
#include "floor/floor.h"
#include "skittle/skittle.h"

bool debug = false;

floor_t* _floor;
skittle_t** skittles;

int current_skittle_index = 0;

extern int window_width;
extern int window_height;

typedef struct SkittleDropper {
    game_t* game;

    vec2f_t velocity;
    hitbox_t* hitbox;
} skittle_dropper_t;

skittle_dropper_t* skittle_dropper_create(game_t* game, vec2i_t init_pos) {
    skittle_dropper_t* dropper = malloc(sizeof(skittle_dropper_t));

    dropper->velocity = (vec2f_t) { 3.0, 0.0 };
    dropper->game = game;
    dropper->hitbox = hitbox_create(init_pos.x, init_pos.y, 50, 50);

    return dropper;
}

void skittle_dropper_update(skittle_dropper_t* dropper, uint64_t frame_count) {
    dropper->hitbox->x += dropper->velocity.x;

    if (dropper->hitbox->x > window_width - dropper->hitbox->width) {
        dropper->hitbox->x = window_width - dropper->hitbox->width;
        dropper->velocity.x = -dropper->velocity.x;
    }

    if (dropper->hitbox->x < 0) {
        dropper->hitbox->x = 0;
        dropper->velocity.x = -dropper->velocity.x;
    }

    // only works properly with vsync
    if (frame_count % 60 * 2 == 0) {
        skittles[current_skittle_index++] = skittle_create(dropper->game, (vec2i_t) {dropper->hitbox->x, dropper->hitbox->y});
        dropper->velocity.x += 0.02;
    }

}

void skittle_dropper_render(skittle_dropper_t* dropper) {
    if (debug)
        hitbox_render_colored(dropper->hitbox, dropper->game->renderer, (vec4i_t) { 250, 0, 250, 255 }, (vec4i_t) { 125, 255, 255, 100 });
}

skittle_dropper_t* skittle_dropper;

game_t* game_create(SDL_Renderer* renderer) {
    game_t* game = malloc(sizeof(game_t));

    game->renderer = renderer;
    game->player = player_create(game, (vec2i_t) {0, 0});

    skittles = malloc(sizeof(skittle_t*) * 1024);

    _floor = floor_create(game);
    skittle_dropper = skittle_dropper_create(game, (vec2i_t) {0, 0});

    return game;
}

void game_destroy(game_t* game) {
    free(skittles);
}

void game_update(game_t* game, const float delta_time, const float global_time, const uint64_t frame_count) {
    player_update(game->player);
    floor_update(_floor);

    skittle_dropper_update(skittle_dropper, frame_count);

    for (int i = 0; i < current_skittle_index; i++)
        skittle_update(skittles[i], global_time);
}

void game_render(const game_t* game) {
    SDL_SetRenderDrawColor(game->renderer, 137, 229, 255, 255);
    SDL_RenderClear(game->renderer);
    player_render(game->player);
    floor_render(_floor);


    skittle_dropper_render(skittle_dropper);

    for (int i = 0; i < current_skittle_index; i++)
        skittle_render(skittles[i]);
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