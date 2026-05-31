#include "Sprite.h"

Sprite::Sprite(SDL_Texture* texture) : Sprite(texture, SDL_Rect{0, 0})
{}

Sprite::Sprite(SDL_Texture* texture, SDL_Rect rect) : texture(texture), rect(rect)
{}

void Sprite::setAlphaMod(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Sprite::setBlandMode(SDL_BlendMode blendMode)
{
    SDL_SetTextureBlendMode(texture, blendMode);
}

void Sprite::setTexture(SDL_Texture* _texture)
{
    texture = _texture;
}

SDL_Texture* Sprite::getTexture() const
{
    return texture;
}

void Sprite::setRect(SDL_Rect _rect)
{
    rect = _rect;
}

SDL_Rect Sprite::getRect() const
{
    return rect;
}