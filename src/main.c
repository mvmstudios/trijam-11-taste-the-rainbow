#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "player/player.h"

int window_width = 800;
int window_height = 600;

float global_time = 0;
uint64_t frame_count = 0;

TTF_Font* font;

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) {
        printf("error initializing sdl: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Trijam 11", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_RESIZABLE);
    if (!window) {
        printf("error creating window: %s\n", SDL_GetError());

        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 
    if (!renderer) {
        printf("error creating renderer: %s\n", SDL_GetError());

        SDL_DestroyWindow(window);
        SDL_Quit();

        return -1;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        return -1;
    }

    /*if (!TTF_Init()) {
        return -1;
    }*/

    /*font = TTF_OpenFont("assets/font/bulky.TTF", 28);
    if (font == NULL)
        return -1;*/

    SDL_RenderSetLogicalSize(renderer, window_width, window_height);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    const Uint8* const keyboard_state = SDL_GetKeyboardState(NULL);

    game_t* game = game_create(renderer);

    uint64_t performance_frequency = SDL_GetPerformanceFrequency();
    uint64_t performance_counter = SDL_GetPerformanceCounter();

    float delta_time = 0;

    bool close_requested = false;
    while (!close_requested) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                close_requested = true;
            else
                game_event(game, event);
        }

        global_time += delta_time;

        game_keyboard_input(game, keyboard_state);
        game_update(game, delta_time, global_time, frame_count);
        game_render(game);

        SDL_RenderPresent(renderer);
    
        uint64_t performance_counter_at_end = SDL_GetPerformanceCounter();
        uint64_t elapsed = performance_counter_at_end - performance_counter;

        delta_time = (float) elapsed / (float) performance_frequency;

        performance_counter = performance_counter_at_end;

        frame_count++;
    }

    game_destroy(game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}