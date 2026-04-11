#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <SDL.h>
#include <SDL_events.h>

class MainMenu final
{
    public:
        void handleEvent(SDL_Event &e);
        void render(SDL_Renderer *renderer);
};
#endif