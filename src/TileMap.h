#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <SDL.h>

#include <cstdint>
#include <string>
#include <vector>

enum TileIds : uint16_t
{
  INVALID = 0
};

struct Tile
{
    uint16_t id;
    SDL_Point position;
};

struct MapLayer
{
    uint16_t id;
    std::vector<Tile> tiles;
};

class TileMap
{
    public:
        // TODO: Temp
        static TileMap* create(
          uint16_t width, 
          uint16_t height,
          uint8_t tileSize,
          std::string tilesheetPath,
          std::vector<int> data
        );
        //static TileMap::load(std::string path);
        TileMap(
          uint16_t width, 
          uint16_t height,
          uint8_t tileSize,
          SDL_Surface* tilesheetSurface
        );
        ~TileMap();
        uint16_t getWidth() const;
        uint16_t getHeidth() const;
        uint8_t getTileSize() const;
        SDL_Surface* getTilesheetSurface() const;
        void addLayer(MapLayer layer);
        bool contains(MapLayer layer);
        std::vector<MapLayer> getLayers();

    private:
        uint16_t width, height;
        uint8_t tileSize;
        SDL_Surface* tilesheetSurface;
        std::vector<MapLayer> layers;
};
#endif