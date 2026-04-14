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
    private:
        std::string name;
        int x, y;
};
#endif