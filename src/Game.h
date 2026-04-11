#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include <string>

class Game final
{
    public:
        Game();
        ~Game();
        int run();
    private:
        SDL_Renderer* renderer;

        SDL_Texture* loadTexture(std::string filename);
};
#endif
