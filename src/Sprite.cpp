#include "Sprite.h"
#include "utils.h"

Sprite::Sprite()
{}

// TODO: Duplicate code needs to be removed.
Sprite* Sprite::load(std::string path)
{
    auto sprite = new Sprite();
    SDL_Surface* sprite_surface;
    sprite_surface = IMG_Load(path.c_str());
    if(!sprite_surface) {
        std::cerr << __func__ << ": Unable to create a surface from a file \n";
        return sprite;
    }
    std::cerr << "Load file " << path.c_str() << "\n"; // INFO
    sprite->setSurface(sprite_surface);
    return sprite;
}

void Sprite::setClip(SDL_Rect _clip)
{
    clip = _clip;
}

SDL_Rect Sprite::getClip() const
{
    return clip;
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y)
{
    auto texture = SDL_CreateTextureFromSurface(renderer, this->surface);

    SDL_Rect src{x, y, clip.w, clip.h};
    SDL_RenderCopy(renderer, texture, &clip, &src);
    SDL_DestroyTexture(texture);
}

void Sprite::draw(SDL_Renderer* renderer, SDL_Point position)
{
    draw(renderer, position.x, position.y);
}

