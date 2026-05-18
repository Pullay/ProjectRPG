#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "Map.h"
#include "Player.h"
#include "Sprite.h"
#include "State.h"
#include "StateManager.h"

class MapState final : public State
{
    public:
        MapState(StateManager* stateManager);
        ~MapState();
        void update(float deltaTime) override;
        void render() override;

    private:
        StateManager* stateManager;
        Map* map;
        Player* player;
        Sprite* playerSprite;
        Sprite* mapTileSet;

        void movePlayerByInput(SDL_KeyboardEvent event);
        void renderMap();
        void renderPlayer();
};
#endif