#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>

#include <SDL_rect.h>
#include <string>

class Player
{
    public:
        enum State : uint8_t
        {
            IDLE = 0, WALK_UP, WALK_LEFT, WALK_DOWN,WALK_RIGHT, ATTACK, DEATH
        };

        Player(const std::string name, SDL_Point position);
        std::string getName() const;
        void move(const int mx, const int my);
        SDL_Point getPosition() const;
        void setState(State state);
        Player::State getState() const;

    private:
        const std::string name;
        SDL_Point position;
        State state;
};
#endif