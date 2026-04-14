#include "MapState.h"
#include "utils.h"

MapState::MapState()
{
    // init
    map = new Map{20, 15};
}

MapState::~MapState()
{
    delete map;
    map = nullptr;
}

void MapState::update()
{}

void MapState::render(SDL_Renderer* renderer)
{
    renderMap(renderer);
}

// PRIVATE
void MapState::renderMap(SDL_Renderer* renderer)
{
    SDL_Texture* mapTileSet = loadTexture(renderer,  "assets/map_tiles.png");
    SDL_Rect src{32, 0, 32, 32};
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            draw(renderer, mapTileSet, src, x * 32, y * 32);

            x++;
            if (x >= map->getWidth()) {
                x = 0;
                y++;
                if (y >= map->getHidth()) y = 0;
            }
        }
    }
}