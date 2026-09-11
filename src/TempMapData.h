#ifndef TEMPMAPDATA_H_
#define TEMPMAPDATA_H_

#include "MapData.h"

class TempMapData : public MapData
{
    public:
        uint16_t getWidth() override;
        uint16_t getHeight() override;
        uint16_t getTileSize()override;
        std::string getTilesetPath()override;
        std::vector<uint16_t> getTiles() override;
};
#endif