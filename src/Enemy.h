#ifndef ENEMY_H_
#define ENEMY_H_

#include "GameObject.h"
#include "Sprite.h"

#include <string>

class Enemy : public GameObject
{
    public:
        Enemy(Sprite* sprite);
        ~Enemy() override;
        Sprite* getSprite();

    private:
        Sprite* sprite;
};
#endif