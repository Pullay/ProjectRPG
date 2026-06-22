#ifndef ENEMY_H_
#define ENEMY_H_

#include "GameObject.h"

#include <SDL_rect.h>

#include <string>

class Enemy : public GameObject
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