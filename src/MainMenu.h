#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "GameState.h"

#include <SDL.h>
#include <SDL_events.h>

class MainMenu final : public GameState
{
    public:
        ~MainMenu();
        void update();
        void render(SDL_Renderer *renderer);
};
#endif