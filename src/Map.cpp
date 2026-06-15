#include "Map.h"

Map::Map(uint8_t width, uint8_t height) : width(width), height(height)
{}

uint8_t Map::getWidth() const
{
    return width;
}

uint8_t Map::getHidth() const
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
