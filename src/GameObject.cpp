#include "GameObject.h"

void GameObject::setPosition(Vector2 position)
{
    this->position = position;
    bounds.x = position.x;
    bounds.y = position.y;
}

Vector2 GameObject::getPosition() const
{
    return position;
}

Rect GameObject::getBounds() const
{
    return bounds;
}
bool GameObject::isColliding(GameObject* other)
{
    if (!collisionActive) {
        return false;
    }

    Rect this_bounds = this->getBounds();
    Rect other_bounds = other->getBounds();
    return this->checkCollision(this_bounds, other_bounds);
}

void GameObject::resolveCollision(GameObject* other)
{
    if (!collisionActive) {
        return;
    }

    Rect this_bounds = this->getBounds();
    Rect other_bounds = other->getBounds();
    if (this->checkCollision(this_bounds, other_bounds)) {
        float dx = (this_bounds.x + this_bounds.width / 2) - (other_bounds.x + other_bounds.width / 2);
        float dy = (this_bounds.y + this_bounds.height / 2) - (other_bounds.y + other_bounds.height / 2);

        float overlap_x = (this_bounds.width / 2 + other_bounds.width / 2) - std::abs(dx);
        float overlap_y = (this_bounds.height / 2 + other_bounds.height / 2) - std::abs(dy);

        if (overlap_x < overlap_y) {
            if (dx > 0) {
                position.x += overlap_x;
            } else {
                position.x -= overlap_x;
                velocity.x = 0;
            }
        } else {
            if (dy > 0) {
                position.y += overlap_y;
            } else {
                position.y -= overlap_y;
                velocity.y = 0;
            }
        }
        setPosition(position);
    }
}

// PRIVATE
bool GameObject::checkCollision(Rect a, Rect b)
{
    //The sides of the rectangles
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.width;
    topA = a.y;
    bottomA = a.y + a.height;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.width;
    topB = b.y;
    bottomB = b.y + b.height;

    //If any of the sides from A are outside of B
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

    //If none of the sides from A are outside B
    return true;
}