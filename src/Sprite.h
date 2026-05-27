#ifndef SPRIITE_H_
#define SPRIITE_H_

#include <SDL.h>

class Sprite
{
    public:
        Sprite() = default;
        Sprite(SDL_Texture* texture);
        void setAlphaMod(Uint8 alpha);
        void setBlandMode(SDL_BlendMode blendMode);
        void setTexture(SDL_Texture* texture);
        SDL_Texture* getTexture() const;

    private:
        SDL_Texture* texture = nullptr;
};
#endif