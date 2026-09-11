#ifndef ENEMY_H_
#define ENEMY_H_

#include "RenderObject.h"
#include "Sprite.h"

class Enemy : public RenderObject
{
    public:
        Enemy(Sprite* sprite);
        ~Enemy() override;
};
#endif