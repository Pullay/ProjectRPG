#include "SpriteView.h"
#include "utils.h"

SpriteView::SpriteView()
{}

void SpriteView::add(Sprite* sprite)
{
    sprites.push_back(sprite);
}

void SpriteView::render(SDL_Renderer* renderer)
{
    for (auto sprite : sprites) {
        sprite->render(renderer);
    }
}