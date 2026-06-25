#ifndef SPRIITE_H_
#define SPRIITE_H_

#include "Image.h"

#include <SDL.h>

#include <string>

class Sprite : public Image
{
    public:
        Sprite();
        static Sprite* load(std::string path);
        void setClip(SDL_Rect rect);
        SDL_Rect getClip() const;
        void draw(SDL_Renderer* renderer, int x, int y);
        void draw(SDL_Renderer* renderer, SDL_Point position);

    private:
        SDL_Rect clip;
};
#endif