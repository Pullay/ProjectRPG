#ifndef GAME_H
#define GAME_H

#include "State.h"
#include <SDL.h>

class Game final
{
    public:
        Game();
        ~Game();
        int run();
    private:
        SDL_Renderer* renderer;
        State* currentState;

        void changeState(State* state);
};
#endif
