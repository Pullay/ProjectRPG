#ifndef MAP_H_
#define MAP_H_

#include "GameState.h"
#include <SDL.h>

#include <SDL.h>
#include <vector>

struct MapLayer
{
    std::vector<int> tiles;
};

class Map : public GameState
{
    public:
        Map(int width, int height);
        ~Map();
        int getWidth() const;
        int getHidth() const;
        void addLayer(MapLayer layer);
        std::vector<MapLayer> getLayers();
        void update();
        void render(SDL_Renderer *renderer);
    private:
        int width, height;
        std::vector<MapLayer> layers;
};
#endif