#include "MainMenuState.h"
#include "Game.h"
#include "MapState.h"
#include "utils.h"

#include <SDL_ttf.h>

MainMenuState::MainMenuState(StateManager* stateManager) : stateManager(stateManager)
{
   initialize();
}

MainMenuState::~MainMenuState()
{
    delete background;
    background = nullptr;
    delete button;
    button = nullptr;
    if (font != nullptr) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

bool MainMenuState::initialize()
{
    font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 24);
    background = Image::load("assets/gui/main_menu.png");
    button = new Button(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2, 84, 42);
    button->addText("Start", font, {0, 255, 0, 255}, 10, 10);
    return true;
}

void MainMenuState::update(const float& deltaTime)
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
    background->draw(renderer, 0, 0);
    button->draw(renderer);
}
