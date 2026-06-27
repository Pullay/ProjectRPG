#ifndef ENEMY_H_
#define ENEMY_H_

#include "GameObject.h"
#include "Sprite.h"

#include <SDL_rect.h>

#include <string>

class Enemy : public GameObject
{
    public:
        Enemy(std::string name, Sprite* sprite);
        std::string getName() const;
        void setPosition(int nx, int ny);
        SDL_Point getPosition() const;
        void update(const float& deltaTime) override;
        void render(SDL_Renderer *renderer) override;

    private:
        std::string name;
        Sprite* sprite;
        SDL_Point position;
};
#endif