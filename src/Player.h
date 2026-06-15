#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>

#include <string>

class Player
{
    public:
        enum State : uint8_t
        {
            IDLE = 0, WALK_UP, WALK_LEFT, WALK_DOWN,WALK_RIGHT, ATTACK, DEATH
        };

        Player(const std::string name, int x, int y);
        ~Player();
        std::string getName() const;
        void move(int mx, int my);
        int getX() const;
        int getY() const;
        void setState(State state);
        Player::State getState();

    private:
        const std::string name;
        int x, y;
        State state;
};
#endif