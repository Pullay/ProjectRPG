#include "GameObject.h"

SDL_Rect GameObject::getCollider()
{
    return collider;
}

// AABB Collision Detection
// @source https://lazyfoo.net/tutorials/SDL/27_collision_detection/index.php
bool GameObject::checkCollision(GameObject* object)
{
    if (!object) {
        return true;
    }

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = collider.x;
    rightA = collider.x + collider.w;
    topA = collider.y;
    bottomA = collider.y + collider.h;

    leftB = object->getCollider().x;
    rightB = object->getCollider().x + object->getCollider().w;
    topB = object->getCollider().y;
    bottomB = object->getCollider().y + object->getCollider().h;

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