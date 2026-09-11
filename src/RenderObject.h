#ifndef RENDEROBJECT_H_
#define RENDEROBJECT_H_

#include "GameObject.h"
#include "Sprite.h"

class RenderObject : public GameObject
{
    public:
        RenderObject();
        ~RenderObject();
        Sprite* getSprite();

    protected:
        Sprite* sprite;
};
#endif