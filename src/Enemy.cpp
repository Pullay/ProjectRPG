#include "Enemy.h"

Enemy::Enemy(const std::string name, SDL_Point position, Sprite* sprite)
  : name(name)
  , sprite(sprite)
{
    this->setCollider({0, 0, 24, 32});
    this->setPosition(position);
}

std::string Enemy::getName() const
{
    return name;
}

void Enemy::update(const float& deltaTime)
{}

void Enemy::render(SDL_Renderer *renderer)
{
    sprite->draw(renderer, this->getPosition());
}