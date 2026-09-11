#ifndef MAPSCENE_H_
#define MAPSCENE_H_

#include "BaseScene.h"
#include "Enemy.h"
#include "Game.h"
#include "MovementSystem.h"
#include "Player.h"
#include "SpriteView.h"
#include "TileMap.h"
#include "TileMapView.h"

#include <cstdint>
#include <string>

class MapScene final : public BaseScene
{
    public:
        const std::string PLAYER_SPRITESHEET_FILE = "assets/player.png";
        const std::string ENEMIES_SPRITESHEET_FILE = "assets/player.png";

        MapScene();
        ~MapScene() override;
        bool initialize();
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        TileMap* map;
        Player* player;
        MovementSystem* movementSystem;
        TileMapView* mapView;
        SpriteView* spriteView;
};
#endif