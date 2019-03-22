module taste_the_rainbow.entity.entity;

import bindbc.sdl;
import taste_the_rainbow.rendering.renderable;

final enum EntityType {

    player,

}

abstract class Entity : IRenderable {

    private:
        static int id;
        static EntityType type;

}

class Player : Entity {

    private:
        static int id = 1;
        static int type = EntityType.player;

    public:
        void update(float deltaTime) {
        }

        void render(SDL_Renderer* renderer) {
            SDL_Rect rect = SDL_Rect(0, 0, 64, 64);

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &rect);
        }

}
