#include "Map.h"

#include <SDL_image.h>

//TODO: Add a map loading from the file system
Map::Map(int width, int height) : width(width), height(height)
{
    // TODO: temp
    // init map
    int i, j;
    MapLayer layer;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
           layer.tiles.push_back(1);
        }
    }
    layers.push_back(layer);
}

Map::~Map()
{}

int Map::getWidth() const
{
    return width;
}

int Map::getHidth() const
{
    return height;
}

void Map::addLayer(MapLayer layer)
{
    layers.push_back(layer);
}

std::vector<MapLayer> Map::getLayers()
{
    return layers;
}

void Map::update()
{}

void Map::render(SDL_Renderer *renderer)
{
    SDL_Texture* mapTileSet = IMG_LoadTexture(renderer, "assets/map_tiles.png");
    SDL_Rect src{32, 0, 32, 32}; // r:1 c:2
    int x = 0, y = 0;
    for (auto layer : layers) {
        for (auto tile : layer.tiles) {
            SDL_Rect dst{x * 32, y* 32, 32, 32};
            SDL_RenderCopy(renderer, mapTileSet, &src, &dst);

            x++;
            if (x >= width) {
                x = 0;
                y++;
                if (y >= height) y = 0;
            }
        }
    }
}