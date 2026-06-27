#include "Player.h"

Player::Player(const std::string name, Sprite* sprite)
  : name(name)
  , sprite(sprite)
  , position({0, 0})
  , velocity({0, 0})
  , state(State::IDLE)
{
    this->collider = {position.x, position.y, 24, 32};
}

Player::~Player()
{}

std::string Player::getName() const
{
    return name;
}

void Player::addClip(State state, SDL_Rect rect)
{
    clips[state] = rect;
}

void Player::move(MoveDirection direction)
{
    switch (direction) {
        case Player::MoveDirection::UP:
            velocity.y -= 1;
            state = WALK_UP;
            break;
        case Player::MoveDirection::DOWN:
            velocity.y += 1;
            state = WALK_DOWN;
            break;
        case Player::MoveDirection::LEFT:
            velocity.x -= 1;
            state = WALK_LEFT;
            break;
        case Player::MoveDirection::RIGHT:
            velocity.x += 1;
            state = WALK_RIGHT;
            break;
    }
}

void Player::setPosition(int nx, int ny)
{
    position = {nx, ny};
    this->collider.x = nx;
    this->collider.y = ny;
}

SDL_Point Player::getPosition() const
{
    return position;
}

Player::State Player::getState() const
{
    return state;
}

void Player::update(const float& deltaTime)
{
    if (velocity.x == 0 && velocity.y == 0) {
        return;
    }

    position.x += velocity.x;
    velocity.x = 0;
    position.y += velocity.y;
    velocity.y = 0;
    // update collider
    this->collider.x = position.x;
    this->collider.y = position.y;
}

void Player::stop()
{
    velocity = {0, 0};
}

void Player::render(SDL_Renderer *renderer)
{
    sprite->draw(renderer, position);
}