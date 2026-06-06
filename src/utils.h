#include "Sprite.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

inline void drawSprite(SDL_Renderer* renderer, Sprite sprite, int x, int y)
{
    SDL_Rect src = sprite.getRect();
    SDL_Rect dst{x, y, src.w, src.h};
    SDL_RenderCopy(renderer, sprite.getTexture(), &src, &dst);
}

inline void drawText(SDL_Renderer* renderer, std::string text, TTF_Font* font, SDL_Color textcolor, SDL_Rect rect)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), textcolor);
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    rect.w = text_surface->w;
    rect.h = text_surface->h;
    SDL_RenderCopy(renderer, text_texture,NULL, &rect);
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}