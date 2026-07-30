#include "TileMap.h"

#include <SDL_image.h>

/** * @return TileMap|nullptr Warning!Returns a null pointer in case of an error */
TileMap* TileMap::create(
  uint16_t width, 
  uint16_t height,
  uint8_t tileSize,
  std::string tilesheetPath,
  std::vector<int> data
)
{
    SDL_Surface* tilesheet_surface = nullptr;
    tilesheet_surface = IMG_Load(tilesheetPath.c_str());
    if (!tilesheet_surface) {
        SDL_LogError(0, "%s:%d Unable to create a surface from a file", __FILE__, __LINE__);
        return nullptr;
    }

    SDL_LogInfo(0, "Load file %s", tilesheetPath.c_str());
    auto map = new TileMap(width, height, tileSize, tilesheet_surface);
    MapLayer layer;
    int x = 0, y = 0;
    for (const int id :data) {
        if (id == TileIds::INVALID) {
            continue;
        }
        Tile tile;
        tile.id = id;
        tile.position = {x * 32, y * 32};
        layer.tiles.push_back(tile);

        x++;
        if (x >= map->getWidth()) {
            x = 0;
            y++;

            if (y >= map->getHeidth()) {
                y = 0;
            }
        }
    }
    map->addLayer(layer);
    return map;
}

TileMap::TileMap(
  uint16_t width, 
  uint16_t height,
  uint8_t tileSize,
  SDL_Surface* tilesheetSurface
)
  : width(width)
  , height(height)
  , tileSize(tileSize)
  , tilesheetSurface(tilesheetSurface)
{}

TileMap::~TileMap()
{
    SDL_FreeSurface(tilesheetSurface);
    tilesheetSurface = nullptr;
}

uint16_t TileMap::getWidth() const
{
    return width;
}

uint16_t TileMap::getHeidth() const
{
    return height;
}

uint8_t TileMap::getTileSize() const
{
    return tileSize;
}

SDL_Surface* TileMap::getTilesheetSurface() const
{
    return tilesheetSurface;
}

void TileMap::addLayer(MapLayer layer)
{
    if (contains(layer)) {
        return;
    }
    layers.push_back(layer);
}

bool TileMap::contains(MapLayer layer)
{
    for (auto layer_it : layers) {
        if (layer_it.id == layer.id) {
            return true;
        }
    }
    return false;
}

std::vector<MapLayer> TileMap::getLayers()
{
    return layers;
}
