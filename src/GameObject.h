#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL.h>

class GameObject
{
    public:
        ~GameObject() {};
        SDL_Rect getCollider();
        bool isTouching(SDL_Rect otherCollider);
        bool isTouching(GameObject* otherObject);
        virtual void update(const float& deltaTime) = 0;
        virtual void render(SDL_Renderer *renderer) = 0;

    protected:
        SDL_Rect collider;
};
#endif