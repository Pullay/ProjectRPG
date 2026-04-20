#include "MainMenuState.h"
#include "MapState.h"
#include "utils.h"

MainMenuState::MainMenuState(Game* game) : game(game)
{}

MainMenuState::~MainMenuState()
{}

void MainMenuState::update()
{
    auto map_state = new MapState(game);
    SDL_KeyboardEvent keyboard_event = game->getEvent().key;
    if (keyboard_event.type == SDL_KEYUP) {
        // change state
        game->setState(map_state);
    }
}

void MainMenuState::render(SDL_Renderer *renderer)
{
    //background
    SDL_Texture* background_texture = loadTexture(renderer, "assets/gui/main_menu.png");
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
}