#ifndef MAPDATA_H_
#define MAPDATA_H_

#include <cstdint>
#include <string>
#include <vector>

// @interface
class MapData
{
    public:
        virtual ~MapData() {}
        virtual uint16_t getWidth() = 0;
        virtual uint16_t getHeight() = 0;
        virtual uint16_t getTileSize() = 0;
        virtual std::string getTilesetPath() = 0;
        virtual std::vector<uint16_t> getTiles() = 0;
};
#endif