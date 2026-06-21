#ifndef MAP_H_
#define MAP_H_

#include <SDL.h>

#include <vector>

struct MapTile
{
    uint16_t id;
};

struct MapLayer
{
    std::vector<MapTile> tiles;
};

class Map
{
    public:
        Map(uint16_t width, uint16_t height);
        uint16_t getWidth() const;
        uint16_t getHidth() const;
        void addLayer(MapLayer layer);
        std::vector<MapLayer> getLayers();

    private:
        uint16_t width, height;
        std::vector<MapLayer> layers;
};
#endif