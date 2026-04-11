#include "MainMenu.h"

#include <SDL_image.h>
#include <SDL.h>

#include <cassert>
#include <iostream>

void MainMenu::handleEvent(SDL_Event &e)
{}

void MainMenu::render(SDL_Renderer *renderer)
{
    //background
    SDL_Texture* backgroundTexture = IMG_LoadTexture(renderer, "assets/gui/main_menu.png");
    assert(backgroundTexture != nullptr);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}