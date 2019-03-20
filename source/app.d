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

	SDL_Delay(5000);
}
