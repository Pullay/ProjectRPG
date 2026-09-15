#include "Rect.h"
#include "Vector2.h"

#include <SDL.h>

#include <cmath>

SDL_Rect sdlFRectToSdlRect(SDL_FRect rect);

inline void blit(SDL_Renderer* renderer, SDL_Texture* texture, Rect rect, Vector2 position)
{
    SDL_Rect src = sdlFRectToSdlRect(rect.toSdlFRect());
    SDL_FRect dst{position.x, position.y, rect.width, rect.height};
    SDL_RenderCopyF(renderer, texture, &src, &dst);
}

inline void drawRect(SDL_Renderer *renderer, Rect rect)
{
    SDL_FRect sdl_rect = rect.toSdlFRect();
    SDL_RenderDrawRectF(renderer, &sdl_rect);
}

inline void drawFillRect(SDL_Renderer *renderer, Rect rect, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_FRect sdl_rect = rect.toSdlFRect();
    SDL_RenderFillRectF(renderer, &sdl_rect);
}

inline SDL_Rect sdlFRectToSdlRect(SDL_FRect rect)
{
    // Floating‑point numbers must always be rounded before conversion.
    return SDL_Rect{static_cast<int>(std::round(rect.w)), static_cast<int>(std::round(rect.h)), static_cast<int>(std::round(rect.x)), static_cast<int>(std::round(rect.y))};
}