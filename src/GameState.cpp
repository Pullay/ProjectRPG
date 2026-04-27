#include "GameState.h"

void GameState::setRenderer(SDL_Renderer* _renderer)
{
    renderer = _renderer;
}

void GameState::handleEvent(SDL_Event _event)
{
    event = _event;
}

// PROTECTED
void GameState::setChildren(GameState* state)
{
    children = state;
    children->handleEvent(event);
    children->setRenderer(renderer);
}
