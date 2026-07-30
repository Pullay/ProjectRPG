#include "Enemy.h"

Enemy::Enemy(Sprite* sprite) : sprite(sprite)
{
    this->bounds = {0, 0, 24, 32};
}

Enemy::~Enemy()
{
    delete sprite;
    sprite = nullptr;
}

Sprite* Enemy::getSprite()
{
    return sprite;
}