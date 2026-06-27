#include "Enemy.h"

Enemy::Enemy(const std::string name, Sprite* sprite)
  : name(name)
  , sprite(sprite)
  , position({0, 0})
{
    this->collider = {0, 0, 24, 32};
}

std::string Enemy::getName() const
{
    return name;
}

void Enemy::setPosition(int nx, int ny)
{
    position = {nx, ny};
    this->collider.x = nx;
    this->collider.y = ny;
}

SDL_Point Enemy::getPosition() const
{
    return position;
}

void Enemy::update(const float& deltaTime)
{

}

void Enemy::render(SDL_Renderer *renderer)
{
    sprite->draw(renderer, position);
}