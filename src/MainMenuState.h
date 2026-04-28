#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "GameState.h"

class MainMenuState final : public GameState
{
    public:
        MainMenuState();
        ~MainMenuState();
        void update(float deltaTime) override;
        void render() override;
};
#endif