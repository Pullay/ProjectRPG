#ifndef GAME_H_
#define GAME_H_

#include "StateManager.h"

#include <SDL.h>

class Game
{
    public:
        static const int WINDOW_WIDTH = 640;
        static const int WINDOW_HEIGHT = 480;

        Game();
        ~Game();
        SDL_Renderer* getRenderer() const;
        void run();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        StateManager* stateManager;
        bool isRunning = false;
        int lastFrameTime = 0; 

        bool initialize();
        void processInput();
        void render();
        void shutdown();
};
#endif
