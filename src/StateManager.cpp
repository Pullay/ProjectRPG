#include "StateManager.h"

StateManager::StateManager(SDL_Renderer* renderer) : renderer(renderer)
{}

void StateManager::handleEvent(SDL_Event _event)
{
    event = _event;
}

SDL_Event StateManager::getEvent()
{
    return event;
}

SDL_Renderer* StateManager::getRenderer()
{
    return renderer;
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

void StateManager::render()
{
    if (currentState)
        currentState->render();
}

