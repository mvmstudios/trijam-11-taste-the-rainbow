#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "game.h"

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        printf("error initializing sdl: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Trijam 11", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
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

    bool close_requested = false;
    while (!close_requested) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                close_requested = true;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}