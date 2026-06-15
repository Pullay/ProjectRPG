#include "Image.h"

Image::Image(SDL_Texture* texture, int x, int y, uint8_t w, uint8_t h)
  : texture(texture)
  , x(x)
  , y(y)
  , w(w)
  , h(h)
{}

SDL_Texture* Image::getTexture() const
{
    return texture;
}

SDL_Rect Image::getRect() const
{
    return SDL_Rect{x, y, h, w};
}
