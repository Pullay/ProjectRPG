#include "Player.h"

Player::Player(const std::string name, Sprite* sprite)
  : name(name)
  , sprite(sprite)
{
    bounds = {0, 0, 24, 32};
}

Player::~Player()
{
    delete sprite;
    sprite = nullptr;
}

std::string Player::getName() const
{
    return name;
}

Sprite* Player::getSprite()
{
    return sprite;
}

void Player::move(float vx, float vy, const float& deltaTime)
{
    this->position.x += vx * (deltaTime / 1000);
    this->position.y += vy * (deltaTime / 1000);
    sprite->setPosition(this->position);
}