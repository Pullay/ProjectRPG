#include "Player.h"

Player::Player(const std::string name) : name(name)
{
    int x = 0, y = 0;
}

Player::~Player()
{}

std::string Player::getName() const
{
    return name;
}

void Player::move(int mx, int my)
{
    x += mx;
    y += my;
}

int Player::getX() const
{
    return x;
}

int Player::getY() const
{
    return y;
}