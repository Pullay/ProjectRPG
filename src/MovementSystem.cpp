#include "MovementSystem.h"
#include <SDL_rect.h>

MovementSystem::MovementSystem(TileMap& map, Player& player) : map(map), player(player), velocity({0, 0})
{}

void MovementSystem::move(float vx, float vy)
{
    velocity = {0, 0};
    velocity.x += vx;
    velocity.y += vy;
}

void MovementSystem::update(const float& deltaTime)
{
    player.move(velocity, deltaTime);
    SDL_FPoint pos;
    pos.x = std::min(std::max(player.getPosition().x, 0.f), static_cast<float>(map.getWidth() * map.getTileSize()) - 32);
    pos.y = std::min(std::max(player.getPosition().y, 0.f), static_cast<float>(map.getHeidth() * map.getTileSize()) - 32);
    player.setPosition(pos);
}