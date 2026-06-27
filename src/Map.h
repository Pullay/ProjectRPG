#ifndef MAP_H_
#define MAP_H_

#include <SDL.h>

#include <cstdint>
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
        Map(uint16_t width, uint16_t height, uint8_t tileSize);
        uint16_t getWidth() const;
        uint16_t getHidth() const;
        uint8_t getTileSize() const;
        void addLayer(MapLayer layer);
        std::vector<MapLayer> getLayers();
        void update(const float& deltaTime);
        void render(SDL_Renderer *renderer);

    private:
        uint16_t width, height;
        uint8_t tileSize;
        std::vector<SDL_Rect> tileset;
        std::vector<MapLayer> layers;
};
#endif