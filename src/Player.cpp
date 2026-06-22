#include "Player.h"

Player::Player(const std::string name, SDL_Point position)
  : name(name)
  , position(position)
  , state(State::IDLE)
{
    this->collider = {position.x, position.y, 24, 32};
}

std::string Player::getName() const
{
    return name;
}

void Player::move(const int mx, const int my)
{
    if (!moving) {
        return;
    }

    position.x += mx;

    if (position.x < 0) {
        position.x -= mx;
    }

    position.y += my;

    if (position.y < 0) {
        position.y -= my;
    }

    // moving player collider
    collider.x = position.x;
    collider.y = position.y;
}

void Player::stop()
{
    moving = false;
}

SDL_Point Player::getPosition() const
{
    return position;
}

void Player::setState(State _state)
{
    state = _state;
    moving = true;
}

Player::State Player::getState() const
{
    return state;
}

