#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "State.h"

class MapState final : public State
{
    public:
        MapState(Game* game);
        ~MapState();
        void update() override;
        void render(SDL_Renderer* renderer) override;

    private:
        Game* game;
        Map* map;
        Player* player;

        void renderMap(SDL_Renderer* renderer);
        void renderPlayer(SDL_Renderer* renderer);
};
#endif