module taste_the_rainbow.game;

import std.container;
import taste_the_rainbow.rendering.renderable: IRenderable;
import taste_the_rainbow.entity.entity;

final class Game : IRenderable {

    private:
        static Game _instance;

        IRenderable renderable;


    public:
        this() {
            _instance = this;

            renderable = new Player;
        }

        static Game instance() {
            if (!_instance)
                _instance = new Game;

            return _instance;
        }

        override void update(float deltaTime) {
            renderable.update(deltaTime);
        }

        import bindbc.sdl: SDL_RenderClear, SDL_SetRenderDrawColor;
        override void render(SDL_Renderer* renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderClear(renderer);

            renderable.render(renderer);
        }
    
}