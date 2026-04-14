#ifndef MAPSTATE_H_
#define MAPSTATE_H_

#include "State.h"
#include "Map.h"

class MapState final : public State
{
    public:
        MapState();
        ~MapState();
        void update();
        void render(SDL_Renderer* renderer);
    private:
        Map* map;

        void renderMap(SDL_Renderer* renderer);
};
#endif