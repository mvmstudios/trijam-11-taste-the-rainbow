void main() {
	import taste_the_rainbow.game;
	import bindbc.sdl;

	loadSDL();

	Game game = Game.instance;

	SDL_Window* window = SDL_CreateWindow("Taste the Rainbow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool closeRequested = false;
	while (!closeRequested) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					closeRequested = true;
					break;
				default:
					break;
			}
		}

		game.update(0.0);
		game.render(renderer);

		SDL_RenderPresent(renderer);
	}
}
