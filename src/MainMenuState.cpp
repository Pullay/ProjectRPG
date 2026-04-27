#include "MainMenuState.h"
#include "MapState.h"
#include "utils.h"

MainMenuState::MainMenuState()
{}

MainMenuState::~MainMenuState()
{}

void MainMenuState::update(float deltaTime)
{
    if (event.key.type == SDL_KEYUP) {
        // change state
        auto map_state = new MapState();
        setChildren(map_state);
        children->update(deltaTime);
    }
}

void MainMenuState::render()
{
    if (children) {
        children->render();
        return;
    }

    //background
    SDL_Texture* background_texture = loadTexture(renderer, "assets/gui/main_menu.png");
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
}