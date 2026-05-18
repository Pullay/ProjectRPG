#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL.h>

class Image
{
    public:
        Image(SDL_Texture* texture, int x, int y, int w, int h);
        SDL_Texture* getTexture() const;
        SDL_Rect getRect() const;

    private:
        SDL_Texture* texture = nullptr;
        int h, w;
        int x, y;
};
#endif