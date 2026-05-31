#ifndef SPRIITE_H_
#define SPRIITE_H_

#include <SDL.h>

// SFML like
class Sprite
{
    public:
        Sprite(SDL_Texture* texture);
        Sprite(SDL_Texture* texture, SDL_Rect rect);
        void setAlphaMod(Uint8 alpha);
        void setBlandMode(SDL_BlendMode blendMode);
        void setTexture(SDL_Texture* texture);
        SDL_Texture* getTexture() const;
        void setRect(SDL_Rect rect);
        SDL_Rect getRect() const;

    private:
        SDL_Texture* texture = nullptr; 
        SDL_Rect rect;
};
#endif