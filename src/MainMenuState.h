#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "Game.h"
#include "MapState.h"
#include "State.h"

class MainMenuState final : public State
{
    public:
        MainMenuState(Game* game);
        ~MainMenuState();
        //State
        void update() override;
        void render(SDL_Renderer* renderer) override;

    private:
        Game* game;
        MapState* mapState;
};
#endif