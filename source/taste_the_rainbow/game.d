module taste_the_rainbow.game;

import taste_the_rainbow.rendering.renderable: IRenderable;
final class Game : IRenderable {

    private:
        static Game _instance;

    public:
        this() {
            _instance = this;
        }

        static Game instance() {
            if (!_instance)
                _instance = new Game;

            return _instance;
        }

        override void update(float deltaTime) {
            
        }

        import bindbc.sdl: SDL_RenderClear, SDL_SetRenderDrawColor;
        override void render(SDL_Renderer* renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderClear(renderer);
        }
    
}