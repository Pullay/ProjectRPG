#include "Button.h"
#include "utils.h"

Button::Button(int x, int y, uint16_t width, uint16_t height)
  : x(x)
  , y(y)
  , width(width)
  , height(height)
{}

Button::~Button()
{
    if (!label) {
        delete label;
        label = nullptr;
    }
}

int Button::getX() const
{
    return x;
}

int Button::getY() const
{
    return y;
}

uint16_t Button::getWidth() const
{
    return width;
}

uint16_t Button::getHeight() const
{
    return height;
}

void Button::addText(std::string text, TTF_Font* font, SDL_Color textcolor, int offsetX, int offsetY)
{
    label = new Label(text, font, x + offsetX, y + offsetY);
    label->setColor(textcolor);
}

Label* Button::getLabel() const
{
    return label;
}

bool Button::isFocus(int mx, int my)
{
    if (mx >= x && mx < x + width && my >= y && my < y + height) {
        return true;
    }
    return false;
}

void Button::draw(SDL_Renderer* renderer)
{
    // primetive button
    SDL_Rect rect {x, y, width, height};
    SDL_RenderDrawRect(renderer, &rect);

    if (label) {
        label->draw(renderer);
    }
}