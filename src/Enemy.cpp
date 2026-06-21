#include "Enemy.h"

Enemy::Enemy(const std::string name, SDL_Point position) : name(name), position(position)
{}

std::string Enemy::getName() const
{
    return name;
}

SDL_Point Enemy::getPosition() const
{
    return position;
}
