#include "Enemy.h"

Enemy::Enemy(Sprite* sprite)
{
    this->sprite = sprite;
    this->bounds = {0, 0, 24, 32};
}

Enemy::~Enemy()
{}