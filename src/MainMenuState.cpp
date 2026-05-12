#include "MainMenuState.h"
#include "MapState.h"
#include "utils.h"

MainMenuState::MainMenuState()
{}

MainMenuState::~MainMenuState()
{}

void MainMenuState::update(float deltaTime)
{
    if (this->event.key.type == SDL_KEYUP) {
        // change state
        auto map_state = new MapState();
        this->setChildren(map_state);
        children->update(deltaTime);
    }
}

void MainMenuState::render()
{
    if (this->children) {
        this->children->render();
        return;
    }

    //background
    SDL_Texture* background_texture = loadTexture(this->renderer, "assets/gui/main_menu.png");
    SDL_RenderCopy(this->renderer, background_texture, NULL, NULL);
}