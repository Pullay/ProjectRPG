#include "IntroState.h"
#include "MainMenuState.h"

#include <iostream>

IntroState::IntroState(StateManager* stateManager) : stateManager(stateManager)
{}

void IntroState::update(float deltaTime)
{
    this->stateManager->changeState(new MainMenuState(this->stateManager));
}

void IntroState::render(SDL_Renderer* renderer)
{
    std::cout << "Intro" << "\n";
}