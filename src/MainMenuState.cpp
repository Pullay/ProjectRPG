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
    // BUG: An error occurs when closing the window.
    if (font != nullptr) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

bool MainMenuState::initialize()
{
    background = Image::load("assets/gui/main_menu.png");
    font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 24);
    button = new Button(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2, 84, 42);
    button->addText("Start", font, {0, 0, 0, 255});
    return true;
}

void MainMenuState::update(const float& deltaTime)
{
    if (!button) {
        std::cerr << __func__ << ": Access to the null pointer is not possible \n";
        return;
    }

    button->setState(Button::State::IDLE);
    SDL_Event e = stateManager->getEvent();
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);

        if (button->isFocus(mx, my)) {
            button->setState(Button::State::HOVER);
            if (e.button.button == SDL_BUTTON_LEFT) {
                button->setState(Button::State::ACTIVE);
                stateManager->changeState(new MapState(stateManager));
            }
        }
    }
}

void MainMenuState::render(SDL_Renderer* renderer)
{
    if (!background || !button) {
        std::cerr << __func__ << ": Access to the null pointer is not possible\n";
        return;
    }

    background->draw(renderer, 0, 0);
    button->draw(renderer);
}
