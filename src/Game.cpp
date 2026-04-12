#include "Game.h"
#include "MainMenu.h"
#include "Map.h"

#include <SDL.h>
#include <SDL_events.h>
#include <SDL_image.h>

#include <climits>
#include <iostream>

Game::Game()
{}

Game::~Game()
{
    delete currentState;
    currentState = nullptr;
}

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

    // init states
    MainMenu* mainMenuState = new MainMenu;
    Map* mapState = new Map{20, 15};

    changeState(mainMenuState);

    // Main loop
     bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    changeState(mapState);
                    break;;
            }
        }

        currentState->update();

        // Draw
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        currentState->render(renderer);

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
void Game::changeState(GameState* state)
{
    if (state != currentState) {
        currentState = state;
    }
}

SDL_Texture* Game::loadTexture(std::string filename)
{
    SDL_Texture *texture;
    texture = IMG_LoadTexture(renderer, filename.c_str());

    if (texture == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }

    return texture;
}
