#include "RenderObject.h"
#include "Sprite.h"

RenderObject::RenderObject()
{}

RenderObject::~RenderObject()
{
    delete sprite;
    sprite = nullptr;
}

Sprite* RenderObject::getSprite()
{
    return sprite;
}