#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL_rect.h>

class GameObject
{
    public:
        ~GameObject() {};
        SDL_Rect getCollider();
        bool checkCollision(GameObject* object);

    protected:
        SDL_Rect collider;
};
#endif