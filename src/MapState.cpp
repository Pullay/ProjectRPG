#include "MapState.h"
#include "Player.h"
#include "utils.h"

MapState::MapState()
{
    // init
    map = new Map(20, 15);
    player = new Player("");
}

MapState::~MapState()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
}

void MapState::update(float deltaTime)
{}

void MapState::render()
{
    renderMap();
    renderPlayer();
}

// PRIVATE
void MapState::renderMap()
{
    SDL_Texture* map_tileset = loadTexture(renderer,  "assets/map_tiles.png");
    SDL_Rect src{32, 32, 32, 32};
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            drawTexture(renderer, map_tileset, src, x * 32, y * 32);

            ++x;
            if (x >= map->getWidth()) {
                x = 0;
                ++y;

                if (y >= map->getHidth())
                    y = 0;
            }
        }
    }
}

void MapState::renderPlayer()
{
    SDL_Texture* player_spirite = loadTexture(renderer, "assets/player.png");
    SDL_Rect src{24, 32, 24, 32};
    drawTexture(renderer, player_spirite, src, player->getX(), player->getY());
}