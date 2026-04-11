#include "Game.h"
#include "MainMenu.h"

#include <SDL_events.h>
#include <SDL_image.h>

#include <iostream>

Game::Game()
{}

Game::~Game()
{}

// TODO: Split into several separate methods
// priority: low
int Game::run()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    SDL_Window* window = SDL_CreateWindow("ProjectRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 380, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    MainMenu mainmenu;
    // Main loop
     bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
            mainmenu.handleEvent(event);
        }

        // Draw
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        mainmenu.render(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// PRIVATE
SDL_Texture* Game::loadTexture(std::string filename)
{
    SDL_Texture *texture;
    texture = IMG_LoadTexture(renderer, filename.c_str());

    if (texture == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }

    return texture;
}
