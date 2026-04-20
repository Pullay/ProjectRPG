#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

inline SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string filename)
{
    SDL_Texture* texture;
    texture = IMG_LoadTexture(renderer, filename.c_str());

    if (!texture) {
        std::cout << SDL_GetError() << "\n";
    }

    return texture;
}

inline void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y)
{
    SDL_Rect dst{x, y};
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

inline void drawTexture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect &src, int x, int y)
{
    SDL_Rect dst{x, y, src.h, src.w};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

inline void drawFont(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color textcolor)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), textcolor);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer,text_surface);
    SDL_RenderCopy(renderer, text_texture, NULL, NULL);
    SDL_FreeSurface(text_surface);
}