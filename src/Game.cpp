#include "Game.h"
#include "MainMenuState.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

Game::Game()
{
    setState(new MainMenuState(this));
}

Game::~Game()
{}

void Game::setState(State* state)
{
    this->state = state;
}

State* Game::getState()
{
    return state;
}

SDL_Event Game::getEvent()
{
    return event;
}

// TODO: Split into several separate methods
// priority: low
int Game::run()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::cout << IMG_GetError << std::endl;
        return -1;
    }

    if (TTF_Init() == -1) {
        std::cout << TTF_GetError << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("ProjectRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    // Main loop
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
            }

            state->update();
        }

        // Draw
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        state->render(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(60);
    }

    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
