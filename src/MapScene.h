#ifndef MAPSCENE_H_
#define MAPSCENE_H_

#include "BaseScene.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include "TileMap.h"

#include <cstdint>
#include <string>
#include <vector>

class MapScene final : public BaseScene
{
    public:
        const std::string MAP_TILESHEET_FILE = "assets/map_tiles.png";
        const std::string PLAYER_SPRITESHEET_FILE = "assets/player.png";
        const std::string ENEMIES_SPRITESHEET_FILE = "assets/player.png";

        MapScene();
        ~MapScene() override;
        bool initialize();
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        const uint16_t maxEnemies = 5;
        TileMap* map;
        Player* player;
        //TODO: Temp
        std::vector<int> mapData = {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
        };
        std::vector<Enemy*> enemies;

        void spawnEnemies();
};
#endif