#include "Enemy.h"

Enemy::Enemy(const std::string name, SDL_Point position) : name(name), position(position)
{
    this->collider = {position.x, position.y, 24, 32};
}

std::string Enemy::getName() const
{
    return name;
}

SDL_Point Enemy::getPosition() const
{
    return position;
}
