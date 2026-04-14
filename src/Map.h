#ifndef MAP_H_
#define MAP_H_

#include <SDL.h>

#include <vector>

struct MapLayer
{
    std::vector<int> tiles;
};

class Map
{
    public:
        Map(int width, int height);
        ~Map();
        int getWidth() const;
        int getHidth() const;
        void addLayer(MapLayer layer);
        std::vector<MapLayer> getLayers();
    private:
        int width, height;
        std::vector<MapLayer> layers;
};
#endif