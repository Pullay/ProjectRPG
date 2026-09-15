#ifndef RECT_H_
#define RECT_H_

#include "Vector2.h"
#include <SDL_rect.h>

#include <cmath>

struct Rect
{
    float x = 0.f, y = 0.f;
    float width = 0.f, height = 0.f;

    float area()
    {
        return width * height;
    }

    Vector2 center()
    {
        if (width == 0 || height == 0) {
            return Vector2{0, 0};
        }
        return Vector2{width/2, height/2};
    }

    SDL_FRect toSdlFRect()
    {
        return SDL_FRect{x, y, width, height};
    }

    bool operator==(Rect other)
    {
        return width == other.width && height == other.height;
    }

    bool operator!=(Rect other)
    {
        return width != other.width || height != other.height;
    }
};
#endif