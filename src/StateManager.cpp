#include "StateManager.h"

StateManager::StateManager()
{}

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

void StateManager::update(float deltaTime)
{
    if (currentState)
        currentState->update(deltaTime);
}

void StateManager::render(SDL_Renderer* renderer)
{
    if (currentState)
        currentState->render(renderer);
}

