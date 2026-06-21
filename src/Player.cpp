#include "Player.h"

Player::Player(const std::string name, SDL_Point position)
  : name(name)
  , position(position)
  , state(State::IDLE)
{}

std::string Player::getName() const
{
    return name;
}

void Player::move(const int mx, const int my)
{
    position.x += mx;
    position.y += my;
}

SDL_Point Player::getPosition() const
{
    return position;
}

void Player::setState(State _state)
{
    state = _state;
}

Player::State Player::getState() const
{
    return state;
}
