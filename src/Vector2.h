#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <SDL_rect.h>

#include <cmath>

struct Vector2
{
    float x = 0.f, y = 0.f;

    float len()
    {
       return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    SDL_FPoint toSdlFPoint()
    {
        return SDL_FPoint{x, y};
    }

    bool operator==(Vector2 other)
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(Vector2 other)
    {
        return x != other.x || y != other.y;
    }

    Vector2 operator+(Vector2 other)
    {
        return Vector2{x + other.x, y + other.y};
    }

    Vector2 operator-(Vector2 other)
    {
        return Vector2{x - other.x, y - other.y};
    }

    Vector2 operator*(Vector2 other)
    {
        return Vector2{x * other.x, y * other.y};
    }

    Vector2 operator/(Vector2 other)
    {
        if (other.x == 0 || other.y == 0) {
            return Vector2{x, y};
        }
        return Vector2{x / other.x, y / other.y};
    }
};
#endif