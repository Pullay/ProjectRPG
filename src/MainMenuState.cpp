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
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, "assets/gui/main_menu.png");
    assert(!background_texture);
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
}