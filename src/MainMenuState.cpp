#include "MainMenuState.h"
#include "MapState.h"

#include <SDL_image.h>

MainMenuState::MainMenuState(StateManager* stateManager) : stateManager(stateManager)
{}

void MainMenuState::update(float deltaTime)
{
    SDL_KeyboardEvent keyboard_event = stateManager->getEvent().key;
    if (keyboard_event.type == SDL_KEYUP) {
        stateManager->changeState(new MapState(stateManager));
    }
}

void MainMenuState::render()
{
    //background
    SDL_Texture* background_texture = IMG_LoadTexture(stateManager->getRenderer(), "assets/gui/main_menu.png");
    SDL_RenderCopy(stateManager->getRenderer(), background_texture, NULL, NULL);
}
