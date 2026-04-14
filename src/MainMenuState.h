#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "State.h"

class MainMenuState final : public State
{
    public:
        ~MainMenuState();
        void update();
        void render(SDL_Renderer *renderer);
};
#endif