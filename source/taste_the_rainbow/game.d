module taste_the_rainbow.game;

final class Game {

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
    
}