#ifndef TILEMAPVIEW_H_
#define TILEMAPVIEW_H_

#include "TileMap.h"

#include <SDL_render.h>

class TileMapView
{
    public:
        TileMapView(TileMap& map);
        void render(SDL_Renderer* renderer);

    private:
        TileMap& map;
};
#endif