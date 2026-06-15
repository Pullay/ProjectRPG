#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL.h>

class Image
{
    public:
        Image(SDL_Texture* texture, int x, int y, uint8_t w, uint8_t h);
        SDL_Texture* getTexture() const;
        SDL_Rect getRect() const;

    private:
        SDL_Texture* texture = nullptr;
        int x, y;
        uint8_t h, w;
};
#endif