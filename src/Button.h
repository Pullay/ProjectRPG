#ifndef BUTTON_H_
#define BUTTON_H_

#include "Label.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

class Button
{
    public:
        Button(int x, int y, int width, int height);
        ~Button();
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        void addText(std::string text, TTF_Font* font, SDL_Color textcolor, int offsetX = 0, int offsetY = 0);
        Label* getLabel();
        bool isFocus(int mx, int my);
        void draw(SDL_Renderer* renderer);

    private:
        int x, y;
        int width, height;
        Label* label;
};
#endif