#ifndef MAPSTATE_H_
#define MAPSTATE_H_


#include "GameState.h"
#include "Map.h"
#include "Player.h"

class MapState final : public GameState
{
    public:
        MapState();
        ~MapState();
        void update(float deltaTime) override;
        void render() override;

    private:
        Map* map;
        Player* player;

        void renderMap();
        void renderPlayer();
};
#endif