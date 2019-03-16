#include "game.h"

game_t* game_create(SDL_Renderer* renderer) {
    game_t* game = malloc(sizeof(game));

    game->renderer = renderer;

    return game;
}

void game_update(game_t* game, const float delta_time, const float global_time, const uint64_t frame_count) {
    
}

void game_render(const game_t* game) {
    SDL_RenderClear(game->renderer);
}

void game_event(game_t* game, const SDL_Event event) {

}

void game_keyboard_input(game_t* game, const Uint8* const keyboard_state) {

}