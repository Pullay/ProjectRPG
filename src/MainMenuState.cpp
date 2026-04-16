#include "MainMenuState.h"
#include "utils.h"

MainMenuState::~MainMenuState()
{}

void MainMenuState::update()
{}

void MainMenuState::render(SDL_Renderer *renderer)
{
    //background
    SDL_Texture* background_texture = loadTexture(renderer, "assets/gui/main_menu.png");
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
}