#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>

#include <string>

enum class PlayerState
{
    IDLE_UP = 0,
    WALKING_UP,
    IDLE_LEFT,
    WALKING_LEFT,
    IDLE_DOWN,
    WALKING_DOWN,
    IDLE_RIGHT,
    WALKING_RIGHT
};

class Player
{
    public:
        Player(const std::string name);
        ~Player();
        std::string getName() const;
        void move(int mx, int my);
        int getX() const;
        int getY() const;

    private:
        const std::string name;
        int x = 0, y = 0;
        PlayerState state;
};
#endif