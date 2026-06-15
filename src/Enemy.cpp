#include "Enemy.h"

Enemy::Enemy(const std::string name, int x, int y) : name(name), x(x), y(y)
{}

std::string Enemy::getName() const
{
    return name;
}

int Enemy::getX() const
{
    return x;
}

int Enemy::getY() const
{
    return y;
}
