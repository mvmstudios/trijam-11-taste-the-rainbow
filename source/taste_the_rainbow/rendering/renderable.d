module taste_the_rainbow.rendering.renderable;

interface IRenderable {

    public:
        void update(float deltaTime);

        import bindbc.sdl: SDL_Renderer;
        void render(SDL_Renderer* renderer);

}