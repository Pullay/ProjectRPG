#ifndef MAP_H_
#define MAP_H_

#include "GameState.h"
#include <SDL.h>

#include <vector>

struct MapTileLayer
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
        std::vector<MapTileLayer> getLayers();
        void update();
        void render(SDL_Renderer *renderer);
    private:
        int width, height;
        std::vector<MapTileLayer> layers;
};
#endif