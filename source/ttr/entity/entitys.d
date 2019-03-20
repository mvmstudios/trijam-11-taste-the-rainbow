module ttr.entity.entitys;

abstract class Entity {
    
    private:
        const int entityId;

    public:
        this(const int entityId) {
            this.entityId = entityId;
        }
        
        void update();

        void render();

}