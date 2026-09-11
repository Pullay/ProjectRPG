#include "TileMap.h"

#include <SDL_image.h>

/** * @return TileMap|nullptr Warning!Returns a null pointer in case of an error */
TileMap* TileMap::load(MapData* mapData)
{
    SDL_Surface* tileset_surface = nullptr;
    tileset_surface = IMG_Load(mapData->getTilesetPath().c_str());
    if (!tileset_surface) {
        SDL_LogError(0, "%s:%d Unable to create a surface from a file", __FILE__, __LINE__);
        return nullptr;
    }

    auto map = new TileMap(
      mapData->getWidth(),
      mapData->getHeight(),
      mapData->getTileSize(),
    tileset_surface
    );
    MapLayer layer;
    for (auto tile_id : mapData->getTiles()) {
        Tile tile{tile_id};
        layer.tiles.push_back(tile);
    }
    map->addLayer(layer);
    return map;
}

TileMap::TileMap(
  uint16_t width, 
  uint16_t height,
  uint8_t tileSize,
  SDL_Surface* tilesetSurface
)
  : width(width)
  , height(height)
  , tileSize(tileSize)
  , tilesetSurface(tilesetSurface)
{}

TileMap::~TileMap()
{
    SDL_FreeSurface(tilesetSurface);
    tilesetSurface = nullptr;
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

SDL_Surface* TileMap::gettilesetSurface() const
{
    return tilesetSurface;
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
