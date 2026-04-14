#include "MainMenuState.h"

#include <SDL_image.h>

#include <cassert>

MainMenuState::~MainMenuState()
{}

void MainMenuState::update()
{}

void MainMenuState::render(SDL_Renderer *renderer)
{
    //background
    SDL_Texture* backgroundTexture = IMG_LoadTexture(renderer, "assets/gui/main_menu.png");
    assert(backgroundTexture != nullptr);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}