#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"
#include "Sprite.h"

#include <SDL_rect.h>

#include <string>

class Player : public GameObject
{
    public:
        enum class Direction : uint8_t
        {
            UP, DOWN, LEFT, RIGHT
        };
        Player(const std::string name, Sprite* sprite);
        ~Player() override;
        std::string getName() const;
        Sprite* getSprite();
        void move(float vx, float vy, const float& deltaTime);

    private:
        const std::string name;
        Sprite* sprite;
};
#endif