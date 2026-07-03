#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <SDL.h>

class GameObject
{
    public:
        ~GameObject() {};

        SDL_Point getPosition() const;
        SDL_Rect getCollider();
        bool isTouching(SDL_Rect otherCollider);
        bool isTouching(GameObject* otherObject);
        virtual void update(const float& deltaTime) = 0;
        virtual void render(SDL_Renderer *renderer) = 0;

    protected:
        SDL_Point position;
        SDL_Rect collider;
    
        void setPosition(SDL_Point position);
        void setCollider(SDL_Rect collider);
};
#endif