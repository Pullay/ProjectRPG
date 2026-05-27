#ifndef INTROSTATE_H_
#define INTROSTATE_H_

#include "State.h"
#include "StateManager.h"

class IntroState final : public State
{
    public:
        IntroState(StateManager* stateManager);
        void update(float deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        StateManager* stateManager;
};
#endif