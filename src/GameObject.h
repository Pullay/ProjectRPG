#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL_rect.h>

// @source https://rishabhdotasara.github.io/tech/2025/09/15/platformer-game-cpp-part3.html
class GameObject
{
    public:
        virtual ~GameObject() = default;
        void setPosition(SDL_FPoint position);
        SDL_FPoint getPosition() const;
        SDL_FRect getBounds() const;
        //This function checks whether the current entity is colliding with another entity.
        bool isColliding(GameObject* other);
        //This function resolves the collision by adjusting the positions or velocities of the entities involved.This function resolves the collision by adjusting the positions or velocities of the entities involved.
        void resolveCollision(GameObject* other);

    protected:
        SDL_FPoint position;
        SDL_FPoint velocity;
        SDL_FRect bounds;
        bool collisionActive = true;

    private:
        // @source https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
        // Copyright Lazy Foo' Productions 2004-2026
        bool checkCollision(SDL_FRect a, SDL_FRect b);
};
#endif