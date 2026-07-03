#include "Player.h"

Player::Player(const std::string name, SDL_Point position, Sprite* sprite)
  : name(name)
  , sprite(sprite)
  , velocity({0, 0})
  , state(State::IDLE)
{
    this->setCollider({0, 0, 24, 32});
    this->setPosition(position);
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

void Player::moveBackward()
{
    switch (state) {
        case Player::State::WALK_UP:
            velocity.y += 1;
            break;
        case Player::State::WALK_DOWN:
            velocity.y -= 1;;
            break;
        case Player::State::WALK_LEFT:
            velocity.x += 1;
            break;
        case Player::State::WALK_RIGHT:
            velocity.x -= 1;
            break;
        default:
            break;
    }
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

    int x = 0, y = 0;
    x = this->getPosition().x;
    x += velocity.x;
    velocity.x = 0;
    y = this->getPosition().y;
    y += velocity.y;
    velocity.y = 0;
    this->setPosition({x, y});
}

void Player::stop()
{
    velocity = {0, 0};
}

void Player::render(SDL_Renderer *renderer)
{
    sprite->draw(renderer, this->getPosition());
}