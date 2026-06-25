#include "Sprite.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

inline SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        std::cerr << "Cannot load texture from file " << path << "\n";
    }

    return texture;
}

inline TTF_Font* loadFont(std::string path, uint8_t fontSize)
{
    TTF_Font* font = nullptr;
    font = TTF_OpenFont(path.c_str(), fontSize);
    if (!font) {
        std::cerr << "Cannot load font from file " << path << "\n";
    }
    return font;
}

inline void drawText(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color textcolor, int x, int y)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), textcolor);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect text_bounds{x, y};
    text_bounds.w = text_surface->w;
    text_bounds.h = text_surface->h;
    SDL_RenderCopy(renderer, text_texture,NULL, &text_bounds);
    SDL_DestroyTexture(text_texture);
    text_texture = nullptr;
    SDL_FreeSurface(text_surface);
    text_surface = nullptr;
}
