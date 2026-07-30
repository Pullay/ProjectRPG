#include <SDL.h>

#include <cmath>

inline void blit(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_FPoint position)
{
    SDL_FRect dst{position.x, position.y};
    if (src.w && src.h) {
        dst.w = static_cast<float>(src.w);
        dst.h = static_cast<float>(src.h);
    }
    SDL_RenderCopyF(renderer, texture, &src, &dst);
}

// Adding two vectors
inline SDL_Point vadd(SDL_Point a, SDL_Point b)
{
    return {a.x + b.x, a.y + b.y};
}

// Subtraction of two vectors
inline SDL_Point vsub(SDL_Point a, SDL_Point b)
{
    return {a.x - b.x, a.y - b.y};
}

// Multiplication of two vectors
inline SDL_Point vmul(SDL_Point a, SDL_Point b)
{
    return {a.x * b.x, a.y * b.y};
}

// Scalar multiplication
inline SDL_Point vsmul(SDL_Point v, int scalar)
{
    return {v.x * scalar, v.y * scalar};
}

// Dividing two vectors
inline SDL_Point vdiv(SDL_Point a, SDL_Point b)
{
    if (b.x == 0 || b.y == 0) {
        return {0, 0};
    }

    return {a.x / b.x, a.y / b.y};
}

// Vector length 
inline float vlen(SDL_Point v)
{
    if (v.x <= 0 || v.y <= 0) {
        return 0;
    }

    return std::sqrt(pow(v.x, 2) + pow(v.y, 2));
}
