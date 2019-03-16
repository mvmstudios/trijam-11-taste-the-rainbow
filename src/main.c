#include <stdio.h>

#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
        return -1;

    SDL_Window* window = SDL_CreateWindow("Trijam 11", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        SDL_Quit();
        return -1;
    }

}