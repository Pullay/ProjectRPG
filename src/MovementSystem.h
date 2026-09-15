#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include "Player.h"
#include "TileMap.h"
#include "Vector2.h"

class MovementSystem
{
    public:
        MovementSystem(TileMap& map, Player& player);
        void move(float vx, float vy);
        void update(const float& deltaTime);

    private:
        TileMap& map;
        Player& player;
        Vector2 velocity;
};
#endif