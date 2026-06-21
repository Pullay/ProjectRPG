#ifndef GAME_H_
#define GAME_H_

#include "StateManager.h"

#include <SDL.h>

class Game final
{
    public:
        static const int WINDOW_WIDTH = 640;
        static const int WINDOW_HEIGHT = 480;

        Game();
        ~Game();
        void run();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        StateManager* stateManager;
        bool running = false;
        int lastFrameTime; 

        bool initialize();
        void processInput();
        void render();
        void shutdown();
};
#endif
