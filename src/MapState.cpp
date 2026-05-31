#include "MapState.h"
#include "Sprite.h"
#include "utils.h"

#include <SDL_image.h>

MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
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
{
    SDL_KeyboardEvent keyboard_event = stateManager->getEvent().key;
    movePlayerByInput(keyboard_event);
}

void MapState::render(SDL_Renderer* renderer)
{
    renderMap(renderer);
    renderPlayer(renderer);
}

// PRIVATE
void MapState::movePlayerByInput(SDL_KeyboardEvent event)
{}

void MapState::renderMap(SDL_Renderer* renderer)
{
    SDL_Texture* map_texture = IMG_LoadTexture(renderer, "assets/map_tiles.png");
    Sprite map_tileset(map_texture, {32, 32, 32, 32});
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            drawSprite(renderer, map_tileset, x * 32, y * 32);

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

void MapState::renderPlayer(SDL_Renderer* renderer)
{
    SDL_Texture* player_texture = IMG_LoadTexture(renderer, "assets/player.png");
    Sprite player_sprite(player_texture, {24, 32, 24, 32});
    drawSprite(renderer, player_sprite, player->getX(), player->getY());
}
