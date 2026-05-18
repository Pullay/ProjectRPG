#include "Sprite.h"

Sprite::Sprite(SDL_Texture* texture) : texture(texture)
{}

void Sprite::setAlphaMod(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Sprite::setBlandMode(SDL_BlendMode blendMode)
{
    SDL_SetTextureBlendMode(texture, blendMode);
}

SDL_Texture* Sprite::getTexture() const
{
    return texture;
}
