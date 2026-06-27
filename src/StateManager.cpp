#include "StateManager.h"
#include <iostream>

StateManager::StateManager()
{}

StateManager::~StateManager()
{
    delete currentState;
    currentState = nullptr;
}

void StateManager::handleEvent(SDL_Event _event)
{
    event = _event;
}

SDL_Event StateManager::getEvent()
{
    return event;
}

void StateManager::changeState(State* state)
{
    if (currentState != nullptr)
      delete currentState;
    currentState = state;
}

State* StateManager::getState()
{
    return currentState;
}

void StateManager::update(const float& deltaTime)
{
    if (currentState)
        currentState->update(deltaTime);
}

void StateManager::render(SDL_Renderer* renderer)
{
    if (currentState)
        currentState->render(renderer);
}

