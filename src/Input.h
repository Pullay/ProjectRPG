#ifndef INPUT_H_
#define INPUT_H_

#include <SDL.h>

#include <cstdint>
#include <unordered_map>

class Input final
{
    public:
        Input();
        void handleEvent(SDL_Event* event);
        bool isKeyUp(SDL_Keycode keycode);
        bool isKeyDown(SDL_Keycode keycode);
        bool isMouseButtonUp(uint8_t key);
        bool isMouseButtonDown(uint8_t key);
        SDL_Point getMousePosition() const;

    private:
        std::unordered_map<SDL_Keycode, bool> keyStates;
        std::unordered_map<Uint8, bool> mouseKeyStates;
        int mouseX = 0, mouseY = 0;
};
#endif