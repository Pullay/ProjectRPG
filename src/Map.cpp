#include "Map.h"

Map::Map(int width, int height) : width(width), height(height)
{}

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
