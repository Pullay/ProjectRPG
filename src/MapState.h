#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "State.h"
#include "Map.h"
#include "Player.h"

class MapState final : public State
{
    public:
        MapState();
        ~MapState();
        void update() override;
        void render(SDL_Renderer* renderer) override;

    private:
        Map* map;
        Player* player;

        void renderMap(SDL_Renderer* renderer);
        void renderPlayer(SDL_Renderer* renderer);
};
#endif