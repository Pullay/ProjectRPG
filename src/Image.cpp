#include "Image.h"

#include <SDL_image.h>
#include <iostream>

Image::Image() : surface(nullptr)
{}

Image::~Image()
{
    free();
}

Image* Image::load(std::string path)
{
    auto image = new Image();
    SDL_Surface* image_surface = nullptr;
    image_surface = IMG_Load(path.c_str());
    if(!image_surface) {
        std::cerr << __func__ << ": Unable to create a surface from a file \n";
        return image;
    }

    std::cerr << "Load file " << path.c_str() << "\n"; // INFO
    image->setSurface(image_surface);
    return image;
}

void Image::setSurface(SDL_Surface* _surface)
{
    surface = _surface;
}

SDL_Surface* Image::getSurface()
{
  return surface;
}

int Image::getWidth() const
{
    return surface->w;
}

int Image::getHeight() const
{
    return surface->h;
}

void Image::draw(SDL_Renderer* renderer, int x, int y)
{
    if (!surface) {
        return;
    }

    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dst{x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dst);
    SDL_DestroyTexture(texture);
}

void Image::free()
{
    if (surface != nullptr) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
}
