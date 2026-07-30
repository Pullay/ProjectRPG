#include "Sprite.h"
#include "utils.h"

#include <SDL_image.h>

/** * @return Sprite*|nullptr WARNING!Returns a null pointer in case of an error */
Sprite* Sprite::load(std::string path)
{
    // You don't need a renderer to create a surface, unlike creating a texture.
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        SDL_LogError(0, "%s:%d Unable to create a surface from a file", __FILE__, __LINE__);
        return nullptr;
    }
    SDL_LogInfo(0, "Load file %s", path.c_str());
    auto sprite = new Sprite(surface);
    return sprite;
};

Sprite::Sprite(SDL_Surface* surface) : surface(surface), position({0, 0})
{}

Sprite::~Sprite()
{
    SDL_FreeSurface(surface);
    surface = nullptr;
}

void Sprite::setPosition(SDL_FPoint position)
{
    this->position = position;
}

SDL_Surface* Sprite::getSurface()
{
    return surface;
}

void Sprite::render(SDL_Renderer* renderer)
{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    const SDL_Rect src{24, 32, 24, 32};
    blit(renderer, texture, src, position);
    SDL_DestroyTexture(texture);
    texture = nullptr;
}