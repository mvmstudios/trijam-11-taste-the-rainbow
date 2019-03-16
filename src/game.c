#include "game.h"

#include "player/player.h"
#include "hitbox/hitbox.h"
#include "sprite/sprite.h"
#include "floor/floor.h"

bool debug = false;

floor_t* _floor;

game_t* game_create(SDL_Renderer* renderer) {
    game_t* game = malloc(sizeof(game_t));

    game->renderer = renderer;
    game->player = player_create(game, (vec2i_t) {0, 0});

    _floor = floor_create(game);

    return game;
}

void game_update(game_t* game, const float delta_time, const float global_time, const uint64_t frame_count) {
    player_update(game->player);
    floor_update(_floor);
}

void game_render(const game_t* game) {
    SDL_SetRenderDrawColor(game->renderer, 137, 229, 255, 255);
    SDL_RenderClear(game->renderer);
    player_render(game->player);
    floor_render(_floor);
}

void game_event(game_t* game, const SDL_Event event) {

}

void game_keyboard_input(game_t* game, const Uint8* const keyboard_state) {
    player_keyboard_input(game->player, keyboard_state);
    debug = keyboard_state[SDL_SCANCODE_O];
}