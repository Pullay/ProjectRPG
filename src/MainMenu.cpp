#include "MainMenu.h"

#include <SDL_image.h>
#include <SDL.h>

#include <cassert>

MainMenu::~MainMenu()
{}

void MainMenu::update()
{}

void MainMenu::render(SDL_Renderer *renderer)
{
    //background
    SDL_Texture* backgroundTexture = IMG_LoadTexture(renderer, "assets/gui/main_menu.png");
    assert(backgroundTexture != nullptr);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}