#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "Enemy.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"
#include "Sprite.h"
#include "State.h"
#include "StateManager.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <vector>

class MapState final : public State
{
    public:
        MapState(StateManager* stateManager);
        ~MapState();
        bool initialize();
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        StateManager* stateManager;
        TTF_Font *font;
        Map* map;
        Player* player;
        Sprite* _playerSprite; // only for delete
        std::vector<Enemy*> enemies;

        void _displayCollisionBox(SDL_Renderer* renderer, GameObject* object);
        void _displayDebugInfo(SDL_Renderer* renderer);
};
#endif