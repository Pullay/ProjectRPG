#ifndef SPRIITE_H_
#define SPRIITE_H_

#include "Vector2.h"

#include <SDL.h>

#include <string>

class Sprite
{
    public:
        static Sprite* load(std::string path);
        Sprite(SDL_Surface* surface);
        ~Sprite();
        void setPosition(Vector2 position);
        SDL_Surface* getSurface();
        void render(SDL_Renderer* renderer);

    private:
        SDL_Surface* surface;
        Vector2 position;
};
#endif