#ifndef SPRITEVIEW_H_
#define SPRITEVIEW_H_

#include "Sprite.h"

#include <SDL_render.h>

#include <vector>

class SpriteView
{
    public:
        SpriteView();
        void add(Sprite* sprite);
        void render(SDL_Renderer* renderer);
    private:
        std::vector<Sprite*> sprites;
};
#endif