#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "MenuButton.h"
#include "State.h"
#include "StateManager.h"

class MainMenuState final : public State
{
    public:
        MainMenuState(StateManager* stateManager);
        ~MainMenuState();
        void update(float deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        StateManager* stateManager;
        MenuButton* button;
};
#endif
