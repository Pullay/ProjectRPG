#include "MainMenuState.h"
#include "Game.h"
#include "MapState.h"
#include "utils.h"

#include <SDL_ttf.h>

MainMenuState::MainMenuState(StateManager* stateManager) : stateManager(stateManager)
{
    TTF_Font* font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 24);
    button = new Button(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2, 84, 42);
    button->addText("Start", font, {0, 255, 0, 255}, 10, 10);
    //TODO: memory leak
    // //TTF_CloseFont(font); 
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

        if (button->isFocus(mx, my)) {
           SDL_MouseButtonEvent mouse_button_event = stateManager->getEvent().button;
           if (mouse_button_event.button == SDL_BUTTON_LEFT)
              stateManager->changeState(new MapState(stateManager));
        }
    }
}

void MainMenuState::render(SDL_Renderer* renderer)
{
    //background
    SDL_Texture* background_texture = loadTexture(renderer, "assets/gui/main_menu.png");
    SDL_QueryTexture(background_texture, NULL, NULL, 0, 0);
    SDL_RenderCopy(renderer, background_texture, NULL, NULL);
    // Main Menu
    button->draw(renderer);
    SDL_DestroyTexture(background_texture);
}
