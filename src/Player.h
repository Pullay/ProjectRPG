#ifndef PLAYER_H_
#define PLAYER_H_

#include "RenderObject.h"
#include "Vector2.h"

#include <string>

class Player : public RenderObject
{
    public:
        enum class Direction : uint8_t
        {
            UP, DOWN, LEFT, RIGHT
        };
        Player(const std::string name, Sprite* sprite);
        ~Player() override;
        std::string getName() const;
        void move(Vector2 velocity, const float& deltaTime);

    private:
        const std::string name;
};
#endif