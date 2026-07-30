#include "Game.h"
#include "BaseScene.h"
#include "IntroScene.h"

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstdlib>

Game::Game(std::string title, uint16_t width, uint16_t height) : head(nullptr)
{
    window = createWindow(title, width, height);
    if (window == nullptr) {
        exit(0);
    }
    initialize();
}

Game::~Game()
{
    // @var BaseScene*|nullptr current
    auto current = head;
    if (!current) {
        while (current != nullptr) {
            // @var BaseScene*|nullptr next
            auto next = current->getNext();
            delete current;
            current = next;
        }
        head = nullptr;
    }
    delete input;
    input = nullptr;
    IMG_Quit();
    TTF_Quit();
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}

bool Game::initialize()
{
    // Init SDL2_image
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    // Init SDL2_ttf
    TTF_Init();
    input = new Input();
    // Set default scene
    pushScene(new IntroScene());
    running = true;
    return true;
}

SDL_Window* Game::getWindow()
{
    return window;
}

Input* Game::getInput() const
{
    return input;
}

void Game::pushScene(BaseScene* scene)
{
    auto new_scene = scene;
    if (head == nullptr) {
        head = new_scene;
        return;
    }

    // @var BaseScene*|nullptr current
    auto current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    current->setNext(new_scene);
}

bool Game::popScene()
{
    if (head == nullptr) {
        return false;
    }

    // @var BaseScene*|nullptr current
    auto current = head;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }

    if (current->getNext() == nullptr) {
        return false;
    }

    auto temp = current->getNext();
    current->setNext(current->getNext()->getNext());
    delete temp; 
    return true;
}

void Game::run()
{
    if (!head) {
        SDL_LogCritical(0, "%s:%d The scene was not prepare",__FILE__, __LINE__);
        quit();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Game loop
    uint8_t last_time = 0;
    const float max_fps = 33.f;
    while (running) {
        uint32_t start_time = SDL_GetTicks();
        float delta_time = start_time - last_time;
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    SDL_LogInfo(0, "Game quit");
                    quit();
                    break;
            }
            input->handleEvent(&event);
        }

        auto current = head;
        while (current != nullptr) {
            if (current->getGame() == nullptr) {
                current->handleGame(this);
            }
            current->update(delta_time);
            // Rendering
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            current->render(renderer);
            current = current->getNext();
            popScene();
        }
        SDL_RenderPresent(renderer);

        // @source https://github.com/GrimRg/SDLEngine/blob/develop/Source/private/Game.cpp
        // @license MIT
        while (SDL_GetTicks() - last_time < max_fps) {
            SDL_Delay(max_fps - (SDL_GetTicks() - last_time));
        }
        last_time = start_time;
    }
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

void Game::quit()
{
    running = false;
}

// PRIVATE
/** * @return SDL_Window*|nullptr WARNING!Returns a null pointer in case of an error */
SDL_Window* Game::createWindow(std::string title, uint16_t width, uint16_t height)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_LogInfo(0, "SDL initialize");
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_LogCritical(0, "%s:%d The window was not created. Detals: %s",__FILE__, __LINE__, SDL_GetError());
        return nullptr;
    }
    return window;
}
