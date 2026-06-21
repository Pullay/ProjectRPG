#include "Map.h"

Map::Map(uint16_t width, uint16_t height) : width(width), height(height)
{}

uint16_t Map::getWidth() const
{
    return width;
}

uint16_t Map::getHidth() const
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
