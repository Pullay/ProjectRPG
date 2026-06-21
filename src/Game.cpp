#include "Game.h"
#include "IntroState.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>

Game::Game()
{
    initialize();
    stateManager  = new StateManager();
    stateManager->changeState(new IntroState(stateManager));  
}

Game::~Game()
{
    shutdown();
    delete stateManager;
    stateManager = nullptr;
}

void Game::run()
{
    if (!stateManager->getState()) {
        return;
    }

    std::cerr << "Game running \n"; // INFO

    // Main loop
    float frame_delay = 1000.0f / 60.0f;
    while (running) {
        float current_time = SDL_GetTicks();
        float delta_time = current_time - lastFrameTime;
        lastFrameTime = current_time;
        processInput();
        stateManager->update(delta_time);
        render();
        // @source https://github.com/falltergeist/falltergeist/blob/develop/src/Game/Game.cpp
        if (frame_delay > delta_time) {
            SDL_Delay(frame_delay - delta_time);
            delta_time += frame_delay - delta_time;
        }
    }
}

// PRIVATE
bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << SDL_GetError() <<"\n";
        return false;
    }

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::cerr << IMG_GetError << "\n";
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << TTF_GetError << "\n";
        return false;
    }

    window = SDL_CreateWindow("ProjectRPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cout << SDL_GetError() << "\n";
        return false;
    }

    running = true;
    lastFrameTime = SDL_GetTicks();
    return true;
}

void Game::processInput()
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        stateManager->handleEvent(event);
    }
}

void Game::render()
{
    if (!stateManager->getState()) {
        return;
    }

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

