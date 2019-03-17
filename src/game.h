#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

#include "player/player.h"

typedef enum GameState {
    GAME_STATE_MENU,
    GAME_STATE_PAUSE,
    GAME_STATE_RUNNING,
    GAME_STATE_LOSE,
    GAME_STATE_RESTART
} game_state_t;

typedef struct Game {
    SDL_Renderer* renderer;

    game_state_t game_state;
    player_t* player;
} game_t;

game_t* game_create(SDL_Renderer* renderer);
void game_destroy(game_t* game);

void game_update(game_t* game, const float delta_time, const float global_time, const uint64_t frame_count);
void game_render(const game_t* game);

void game_event(game_t* game, const SDL_Event event);
void game_keyboard_input(game_t* game, const Uint8* const keyboard_state);

#endif