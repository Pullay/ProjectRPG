#ifndef BUTTON_H_
#define BUTTON_H_

#include "Label.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

class Button
{
    public:
        enum class State : uint8_t
        {
            IDLE, HOVER, ACTIVE
        };
        Button(int x, int y, uint16_t width, uint16_t height);
        ~Button();
        int getX() const;
        int getY() const;
        uint16_t getWidth() const;
        uint16_t getHeight() const;
        void setState(Button::State state);
        // @param offsetX The X-axis text offset relative to the button
        // @param offsetY The Y-axis text offset relative to the button
        void addText(std::string text, TTF_Font* font, SDL_Color textcolor, int offsetX = 0, int offsetY = 0);
        Label* getLabel() const;
        bool isFocus(int mx, int my);
        void update(SDL_Point mousePosition);
        void draw(SDL_Renderer* renderer);

    private:
        int x, y;
        uint16_t width, height;
        Button::State state;
        Label* label;
};
#endif