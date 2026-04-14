#include "Map.h"

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
