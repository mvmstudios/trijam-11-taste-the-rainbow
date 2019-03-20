module taste_the_rainbow.game;

final class Game {

    private:
        Game instance;

    public:
        this() {
            instance = this;
        }

        static Game instance() {
            if (!instance)
                instance = new Game;

            return instance;
        }
    
}