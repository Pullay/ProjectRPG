#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "State.h"

#include <SDL.h>

class GameState: public State
{
    public:
        void setRenderer(SDL_Renderer* renderer);
        void handleEvent(SDL_Event event);

    protected:
        SDL_Renderer* renderer;
        SDL_Event event;
        GameState* children;

        void setChildren(GameState* state);
};
#endif