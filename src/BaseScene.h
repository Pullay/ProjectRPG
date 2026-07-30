#ifndef BASESCENE_H_
#define BASESCENE_H_

#include "Game.h"

#include <SDL_render.h>

// @node
class BaseScene
{
    public:
        virtual ~BaseScene() = default;
        virtual void update(const float& deltaTime) = 0;
        virtual void render(SDL_Renderer *renderer) = 0;
        void setNext(BaseScene* scene);
        BaseScene* getNext();
        void handleGame(Game* game);
        Game* getGame();

    private:
        BaseScene* next = nullptr;
        Game* game = nullptr;
};
#endif
