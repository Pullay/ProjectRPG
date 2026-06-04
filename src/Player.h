#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>

#include <string>

enum class PlayerState
{
    UP = 0, LEFT, DOWN, RIGHT
};

class Player
{
    public:
        Player(const std::string name, int x, int y);
        ~Player();
        std::string getName() const;
        void move(int mx, int my);
        int getX() const;
        int getY() const;
        void setState(PlayerState state);
        PlayerState getState();

    private:
        const std::string name;
        int x = 0, y = 0;
        PlayerState state;
};
#endif