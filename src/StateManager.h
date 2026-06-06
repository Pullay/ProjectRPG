#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include "State.h"

#include <SDL.h>

class StateManager final
{
    public:
        StateManager();
        ~StateManager();
        void handleEvent(SDL_Event event);
        SDL_Event getEvent();
        void changeState(State* state);
        State* getState();
        void update(float deltaTime);
        void render(SDL_Renderer* renderer);

    private:
        SDL_Event event;
        State* currentState = nullptr;
};
#endif