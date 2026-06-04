#include "Game.h"
#include "IntroState.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

Game::Game()
{
    stateManager  = new StateManager();
    stateManager->changeState(new IntroState(stateManager));
}

Game::~Game()
{
    delete stateManager;
    stateManager = nullptr;
    isRunning = false;
    lastFrameTime = 0;
}

SDL_Renderer* Game::getRenderer() const
{
    return renderer;
}

void Game::run()
{
    if (!initialize()) {
        std::cout << "Failed to initialize!" << "\n";
        return;
    }

    // Main loop
    while (isRunning) {
        float current_time = SDL_GetTicks();
        float delta_time = (current_time - lastFrameTime) / 1000.0f;
        lastFrameTime = current_time;
        processInput();
        stateManager->update(delta_time);
        render();
        SDL_Delay(60);
    }

    shutdown();
}

// PRIVATE
bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() <<"\n";
        return false;
    }

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::cout << IMG_GetError << "\n";
        return false;
    }

    if (TTF_Init() == -1) {
        std::cout << TTF_GetError << "\n";
        return false;
    }

    window = SDL_CreateWindow("ProjectRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    isRunning = true;
    lastFrameTime = SDL_GetTicks();
    return true;
}

void Game::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        stateManager->handleEvent(event);
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    stateManager->render(renderer);
    SDL_RenderPresent(renderer);
}

void Game::shutdown()
{
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}

