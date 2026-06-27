#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"
#include "Sprite.h"

#include <SDL.h>

#include <map>
#include <string>

class Player : public GameObject
{
    public:
        enum class MoveDirection : uint8_t
        {
            UP, DOWN, RIGHT, LEFT
        };

        enum State : uint8_t
        {
            IDLE = 0, WALK_UP, WALK_LEFT, WALK_DOWN,WALK_RIGHT, ATTACK, DEATH
        };

        Player(const std::string name, Sprite* sprite);
        ~Player();
        std::string getName() const;
        void addClip(State state, SDL_Rect rect);
        void move(MoveDirection direction);
        void stop();
        void setPosition(int nx, int ny);
        SDL_Point getPosition() const;
        Player::State getState() const;
        void update(const float& deltaTime) override;
        void render(SDL_Renderer *renderer) override;

    private:
        Sprite* sprite;
        std::map<Player::State, SDL_Rect> clips;
        const std::string name;
        SDL_Point position;
        SDL_Point velocity;
        Player::State state;
};
#endif