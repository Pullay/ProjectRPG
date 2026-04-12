#include "Map.h"

#include <iostream>

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

std::vector<MapTileLayer> Map::getLayers()
{
    return layers;
}

void Map::update()
{}

void Map::render(SDL_Renderer *renderer)
{
    std::cout << "WIP" << std::endl;
}