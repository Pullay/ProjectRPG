#include "MapState.h"

#include <SDL_image.h>

MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
    map = new Map(20, 15);
    player = new Player("");
    SDL_Texture* map_texture = IMG_LoadTexture(stateManager->getRenderer(), "assets/map_tiles.png");
    mapTileSet = new Sprite(map_texture);
    SDL_Texture* player_texture = IMG_LoadTexture(stateManager->getRenderer(),  "assets/player.png");
    playerSprite = new Sprite(player_texture);
}

MapState::~MapState()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
    delete mapTileSet;
    mapTileSet = nullptr;
    delete playerSprite;
    playerSprite = nullptr;
}

void MapState::update(float deltaTime)
{
    SDL_KeyboardEvent keyboard_event = stateManager->getEvent().key;
    movePlayerByInput(keyboard_event);
    deltaTime = 0;
}

void MapState::render()
{
    renderMap();
    renderPlayer();
}

// PRIVATE
void MapState::movePlayerByInput(SDL_KeyboardEvent event)
{}

void MapState::renderMap()
{
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            SDL_Rect src{32, 32, 32, 32};
            SDL_Rect dst{x * 32, y * 32,32, 32};
            SDL_RenderCopy(stateManager->getRenderer(), mapTileSet->getTexture(), &src, &dst);

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
    SDL_Rect src{24, 32, 24, 32};
    SDL_Rect dst{player->getX(), player->getY(), 24, 32};
    SDL_RenderCopy(stateManager->getRenderer(), playerSprite->getTexture(), &src, &dst);
}
