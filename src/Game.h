#ifndef GAME_H
#define GAME_H

#include "State.h"

#include <SDL.h>

class Game final
{
    public:
        Game();
        ~Game();
        void setState(State* state);
        State* getState();
        SDL_Event getEvent();
        // WARNING: Do not use inside the State
        int run();

    private:
        SDL_Renderer* renderer;
        SDL_Event event;
        State* state;
};
#endif
