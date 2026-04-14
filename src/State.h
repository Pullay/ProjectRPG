#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SDL.h>

class State
{
    public:
        virtual ~State() {}
        virtual void update() = 0;
        virtual void render(SDL_Renderer *renderer) = 0;
};
#endif