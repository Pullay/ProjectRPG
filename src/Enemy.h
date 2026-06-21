#ifndef ENEMY_H_
#define ENEMY_H_

#include <SDL_rect.h>

#include <string>

class Enemy
{
    public:
        Enemy(std::string name, SDL_Point position);
        std::string getName() const;
        SDL_Point getPosition() const;

    private:
        std::string name;
        SDL_Point position;
};
#endif