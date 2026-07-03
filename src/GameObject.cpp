#include "GameObject.h"

SDL_Point GameObject::getPosition() const
{
    return position;
}

SDL_Rect GameObject::getCollider()
{
    return collider;
}

// AABB Collision Detection
// @source https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
bool GameObject::isTouching(SDL_Rect otherCollider)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = collider.x;
    rightA = collider.x + collider.w;
    topA = collider.y;
    bottomA = collider.y + collider.h;

    leftB = otherCollider.x;
    rightB = otherCollider.x + otherCollider.w;
    topB = otherCollider.y;
    bottomB = otherCollider.y + otherCollider.h;

    if(bottomA <= topB) {
        return false;
    }

    if(topA >= bottomB) {
        return false;
    }

    if(rightA <= leftB) {
        return false;
    }

    if(leftA >= rightB) {
        return false;
    }

    return true;
}

bool GameObject::isTouching(GameObject* otherObject)
{
    if (!otherObject) {
        return true;
    }

    return isTouching(otherObject->getCollider());
}

// PROTECTED
void GameObject::setPosition(SDL_Point _position)
{
    position = _position;
    // update collider
    collider.x = position.x;
    collider.y = position.y;
}

void GameObject::setCollider(SDL_Rect _collider)
{
    collider = _collider;
}