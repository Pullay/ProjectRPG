#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SDL_render.h>

// @interface
class Component
{
    public:
        virtual ~Component() {};
        virtual void update(const float& deltaTime) = 0;
        virtual void render(SDL_Renderer *renderer) = 0;
};
#endif