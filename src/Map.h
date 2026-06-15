#ifndef MAP_H_
#define MAP_H_

#include <SDL.h>

#include <vector>

struct MapTile
{
    uint8_t id;
};

struct MapLayer
{
    std::vector<MapTile> tiles;
};

class Map
{
    public:
        Map(uint8_t width, uint8_t height);
        uint8_t getWidth() const;
        uint8_t getHidth() const;
        void addLayer(MapLayer layer);
        std::vector<MapLayer> getLayers();

    private:
        uint8_t width, height;
        std::vector<MapLayer> layers;
};
#endif