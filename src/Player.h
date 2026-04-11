#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>

#include <string>

class Player
{
    public:
        Player(std::string name);
        ~Player();
        std::string getName() const;
        void update();
        void render(SDL_Renderer *renderer);
    private:
        std::string name;
        int x, y;
};
#endif