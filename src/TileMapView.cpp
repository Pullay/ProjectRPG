#include "TileMapView.h"
#include "Vector2.h"
#include "utils.h"

#include <cmath>

TileMapView::TileMapView(TileMap& map) : map(map)
{}

void TileMapView::render(SDL_Renderer* renderer)
{
    // rendering map
    auto tile_size = map.getTileSize();
    int x = 0, y = 0;
    SDL_Texture* tileset_texture = SDL_CreateTextureFromSurface(renderer, map.gettilesetSurface());
    for (auto layer : map.getLayers()) {
         for (auto tile : layer.tiles) {
            Vector2 pos;
            pos.x = x * tile_size;
            pos.y = y * tile_size;
            Vector2 tileset_offset;
            tileset_offset.x = tile.id * tile_size;
            tileset_offset.y = tile.id * tile_size;
            //The offset along the axes cannot exceed the size of the tile sheet
            if (tileset_offset.x > map.gettilesetSurface()->h
              || tileset_offset.y > map.gettilesetSurface()->w
            ) {
                tileset_offset = {0.f, 0.f};
            }

            Rect rect{tileset_offset.x, tileset_offset.y, static_cast<float>(std::round(tile_size)), static_cast<float>(std::round(tile_size))};
            blit(renderer, tileset_texture, rect, pos);

            x++;
            if (x >= map.getWidth()) {
                x = 0;
                y++;

                if (y >= map.getHeidth()) {
                    y = 0;
                }
            }
        }
    }
    SDL_DestroyTexture(tileset_texture);
    tileset_texture = nullptr;
}