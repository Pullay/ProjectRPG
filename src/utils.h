#include "Sprite.h"

#include <SDL.h>

inline void drawSprite(SDL_Renderer* renderer, Sprite sprite, int x, int y)
{
    SDL_Rect src = sprite.getRect();
    SDL_Rect dst{x, y, src.w, src.h};
    SDL_RenderCopy(renderer, sprite.getTexture(), &src, &dst);
}
