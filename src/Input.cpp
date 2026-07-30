#include "Input.h"

Input::Input()
{}

void Input::handleEvent(SDL_Event* event)
{
    switch (event->type) {
        case SDL_KEYUP:
            if (event->key.repeat == 0) {
                keyStates[event->key.keysym.sym] = false;
            }
            break;
        case SDL_KEYDOWN:
            if (event->key.repeat == 0) {
                keyStates[event->key.keysym.sym] = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            mouseKeyStates[event->button.button] = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseKeyStates[event->button.button] = true;
            break;
        case SDL_MOUSEMOTION:
            mouseX = event->button.x;
            mouseY = event->button.y;
            break;
    }
}

bool Input::isKeyUp(SDL_Keycode keycode)
{
    return keyStates[keycode] == true;
}

bool Input::isKeyDown(SDL_Keycode keycode)
{
    return keyStates[keycode] == false;
}

bool Input::isMouseButtonUp(uint8_t key)
{
    return mouseKeyStates[key] == true;
}

bool Input::isMouseButtonDown(uint8_t key)
{
    return mouseKeyStates[key] == false;
}

SDL_Point Input::getMousePosition() const
{
    return {mouseX, mouseY};
}