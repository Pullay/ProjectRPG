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
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        StateManager* stateManager;
        TTF_Font* font;
        SDL_Renderer* renderer;
        Map* map;
        Player* player;
        Sprite* playerSprite;
        Sprite* enemySprite;
        SDL_Point camera;
        std::vector<Enemy*> enemies;

        void movePlayerByInput(SDL_KeyboardEvent event);
        void spawnEnemies();
        void renderMap();
        void renderPlayer();
        void renderEnemies();
        // TODO: For debug only
        void drawLabel(std::string text, int x, int y);
        void _displayDebugInfo();
        void _displayHitBox(GameObject* object);
};
#endif