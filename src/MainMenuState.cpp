#include "MainMenuState.h"
#include "Game.h"
#include "MapState.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

MainMenuState::MainMenuState(StateManager* stateManager) : stateManager(stateManager)
{
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 32);
    button = new MenuButton(Game::WINDOW_WIDTH/2, Game::WINDOW_HEIGHT/2, 42, 42);
    button->addText(font, "Start", SDL_Color{0, 255, 0, 255});
}

MainMenuState::~MainMenuState()
{
    delete button;
    button = nullptr;
}

void MainMenuState::update(float deltaTime)
{
    SDL_Event e = stateManager->getEvent();
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);

        if (button->onHit(mx, my)) {
           SDL_MouseButtonEvent mouse_button_event = stateManager->getEvent().button;
           if (mouse_button_event.button == SDL_BUTTON_LEFT)
              stateManager->changeState(new MapState(stateManager));
        }
    }
}

void MainMenuState::render(SDL_Renderer* renderer)
{
    //background
    SDL_Texture* background_texture = IMG_LoadTexture(renderer, "assets/gui/main_menu.png");
    SDL_QueryTexture(background_texture, NULL, NULL, 0, 0);
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
    // Start button
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, button->getTextSurface());
    auto dst = button->getRect();
    SDL_RenderCopy(renderer, text_texture, NULL, &dst);
}
