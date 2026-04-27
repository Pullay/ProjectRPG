#ifndef GAME_H
#define GAME_H

#include "GameState.h"

#include <SDL.h>

class Game final
{
    public:
        Game();
        ~Game();
        void run();

    private:
        GameState* state;
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning = true;
        int lastFrameTime;

        bool initialize();
        void processInput();
        void update(float deltaTime);
        void render();
        void shutdown();
};
#endif
