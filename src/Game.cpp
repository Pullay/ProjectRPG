#include "Game.h"
#include "MainMenuState.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

Game::Game()
{
    state = new MainMenuState();
}

Game::~Game()
{
    delete state;
    state = nullptr;
}

void Game::run()
{
    initialize();
    // Main loop
    while (isRunning) {
        float current_time = SDL_GetTicks();
        float delta_time = (current_time - lastFrameTime) / 1000.0f;
        lastFrameTime = current_time;
        processInput();
        update(delta_time);
        render();
        SDL_Delay(16);
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

    window = SDL_CreateWindow("ProjectRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    state->setRenderer(renderer);
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
        state->handleEvent(event);
    }
}

void Game::update(float deltaTime)
{
    state->update(deltaTime);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    state->render();
    SDL_RenderPresent(renderer);
}

void Game::shutdown()
{
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
