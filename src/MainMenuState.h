#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "Button.h"
#include "Image.h"
#include "State.h"
#include "StateManager.h"

#include <SDL_ttf.h>

class MainMenuState final : public State
{
    public:
        MainMenuState(StateManager* stateManager);
        ~MainMenuState();
        bool initialize();
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        StateManager* stateManager;
        TTF_Font* font;
        Image* background;
        Button* button;
};
#endif
