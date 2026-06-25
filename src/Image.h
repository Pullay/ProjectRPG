#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL.h>

#include <string>

class Image
{
    public:
        Image();
        ~Image();
        static Image* load(std::string path);
        void setSurface(SDL_Surface* surface);
        SDL_Surface* getSurface();
        int getWidth() const;
        int getHeight() const;
        void draw(SDL_Renderer* renderer, int x, int y);
        void free();

    protected:
        SDL_Surface* surface;

        void blit();
};
#endif