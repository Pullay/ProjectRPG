#include "Player.h"

Player::Player(const std::string name, Sprite* sprite)
  : name(name)
{
    this->sprite = sprite;
    bounds = {0, 0, 24, 32};
}

Player::~Player()
{}

std::string Player::getName() const
{
    return name;
}

void Player::move(SDL_FPoint velocity, const float& deltaTime)
{
    this->position.x += velocity.x * (deltaTime / 1000);
    this->position.y += velocity.y * (deltaTime / 1000);
    sprite->setPosition(this->position);
}