#ifndef STATE_H_
#define STATE_H_

#include <SDL_render.h>

class State
{
    public:
        virtual ~State() {}
        virtual void update(const float&deltaTime) = 0;
        virtual void render(SDL_Renderer *renderer) = 0;
};
#endif