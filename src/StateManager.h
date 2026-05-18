#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

#include "State.h"

#include <SDL.h>
#include <SDL_events.h>

class StateManager final
{
    public:
        StateManager(SDL_Renderer* renderer);
        void handleEvent(SDL_Event event);
        SDL_Event getEvent();
        SDL_Renderer* getRenderer();
        void changeState(State* state);
        State* getState();
        void update(float deltaTime);
        void render();

    private:
        SDL_Renderer* renderer;
        SDL_Event event;
        State* currentState = nullptr;
};
#endif