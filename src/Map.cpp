#include "Map.h"
#include "utils.h"

Map::Map(uint16_t width, uint16_t height, uint8_t tileSize) 
  : width(width)
  , height(height)
  , tileSize(tileSize)
{
    tileset.push_back({0, 0, tileSize, tileSize});
    tileset.push_back({32, 32, tileSize, tileSize});
}

uint16_t Map::getWidth() const
{
    return width;
}

uint16_t Map::getHidth() const
{
    return height;
}

uint8_t Map::getTileSize() const
{
    return tileSize;
}

void Map::addLayer(MapLayer layer)
{
    layers.push_back(layer);
}

std::vector<MapLayer> Map::getLayers()
{
    return layers;
}

void Map::update(const float& deltaTime)
{}

void Map::render(SDL_Renderer *renderer)
{
    // Do not execute the code if the map is empty.
    if (layers.empty()) {
        return;
    }

    // TODO: temp
    SDL_Texture* map_tileset = loadTexture(renderer,  "assets/map_tiles.png");
    int x = 0, y = 0;
    for (auto layer : layers) {
        for (auto tile : layer.tiles) {
            SDL_Rect src = tileset[tile.id];
            SDL_Rect dst{x * tileSize, y * tileSize, src.w, src.h};
            SDL_RenderCopy(renderer, map_tileset, &src, &dst);

            ++x;
            if (x >= width) {
                x = 0;
                ++y;

                if (y >= height)
                    y = 0;
            }
        }
    }

    SDL_DestroyTexture(map_tileset);
    map_tileset = nullptr;
}