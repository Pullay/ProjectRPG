#ifndef SPRIITE_H_
#define SPRIITE_H_

#include <SDL.h>

#include <string>

class Sprite
{
    public:
        static Sprite* load(std::string path);
        Sprite(SDL_Surface* surface);
        ~Sprite();
        void setPosition(SDL_FPoint position);
        SDL_Surface* getSurface();
        void render(SDL_Renderer* renderer);

    private:
        SDL_Surface* surface;
        SDL_FPoint position;
};
#endif