#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "Map.h"
#include "Player.h"
#include "State.h"
#include "StateManager.h"

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

        void movePlayerByInput(SDL_KeyboardEvent event);
        void renderMap(SDL_Renderer* renderer);
        void renderPlayer(SDL_Renderer* renderer);
        void renderTextBox(SDL_Renderer* renderer);
};
#endif