#ifndef ENEMY_H_
#define ENEMY_H_

#include "GameObject.h"
#include "Sprite.h"

#include <string>

class Enemy : public GameObject
{
    public:
        Enemy(std::string name, SDL_Point position, Sprite* sprite);
        std::string getName() const;
        void update(const float& deltaTime) override;
        void render(SDL_Renderer *renderer) override;

    private:
        std::string name;
        Sprite* sprite;
};
#endif