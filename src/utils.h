#pragma once

#include <SDL_image.h>

#include <iostream>

inline SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string filename)
{
    SDL_Texture* texture;
    texture = IMG_LoadTexture(renderer, filename.c_str());

    if (texture == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }

    return texture;
}

inline void draw(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect &src, int x, int y)
{
    SDL_Rect dst{x, y, src.h, src.w};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}