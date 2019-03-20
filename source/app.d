void main() 
{
	import std.stdio: writeln;
	import bindbc.sdl;

	SDLSupport ret = loadSDL();
	if (ret != sdlSupport) {
		if (ret == SDLSupport.noLibrary) {
			writeln("No library");
		}

		if (ret == SDLSupport.badLibrary) {
			writeln("Wrong library");
		}
	}

	SDL_Window* window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool closeRequested = false;
	while (!closeRequested) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					closeRequested = true;
					break;
				default:
					break;
			}
		}

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

}
