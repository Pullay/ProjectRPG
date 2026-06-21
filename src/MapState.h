#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "State.h"
#include "StateManager.h"

#include <SDL.h>

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
        Map* map;
        Player* player;
        SDL_Point camera;
        std::vector<Enemy*> enemies;

        void movePlayerByInput(SDL_KeyboardEvent event);
        void spawnEnemies();
        void renderMap(SDL_Renderer* renderer);
        void renderPlayer(SDL_Renderer* renderer);
        void renderEnemies(SDL_Renderer* renderer);
        void renderTextBox(SDL_Renderer* renderer);
};
#endif