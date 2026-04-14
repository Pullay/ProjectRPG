#include "Player.h"

Player::Player(std::string name) : name(name)
{}

Player::~Player()
{}

std::string Player::getName() const
{
    return name;
}
