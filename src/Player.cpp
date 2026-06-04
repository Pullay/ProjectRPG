#include "Player.h"

Player::Player(const std::string name, int x, int y) : name(name), x(x), y(y)
{}

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

void Player::setState(PlayerState _state)
{
    state = _state;
}

PlayerState Player::getState()
{
    return state;
}
