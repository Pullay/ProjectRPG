#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Rect.h"
#include "Vector2.h"

// @source https://rishabhdotasara.github.io/tech/2025/09/15/platformer-game-cpp-part3.html
class GameObject
{
    public:
        virtual ~GameObject() = default;
        void setPosition(Vector2 position);
        Vector2 getPosition() const;
        Rect getBounds() const;
        //This function checks whether the current entity is colliding with another entity.
        bool isColliding(GameObject* other);
        //This function resolves the collision by adjusting the positions or velocities of the entities involved.This function resolves the collision by adjusting the positions or velocities of the entities involved.
        void resolveCollision(GameObject* other);

    protected:
        Vector2 position;
        Vector2 velocity;
        Rect bounds;
        bool collisionActive = true;

    private:
        // @source https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
        // Copyright Lazy Foo' Productions 2004-2026
        bool checkCollision(Rect a, Rect b);
};
#endif