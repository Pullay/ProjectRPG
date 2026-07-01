#include "Button.h"
#include "utils.h"
#include <cstdint>

Button::Button(int x, int y, uint16_t width, uint16_t height)
  : x(x)
  , y(y)
  , width(width)
  , height(height)
  , state(Button::State::IDLE)
  , label(nullptr)
{}

Button::~Button()
{
    if (label != nullptr) {
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

void Button::setState(Button::State _state)
{
    state = _state;
}

// TODO: It is necessary to prevent the text from going beyond the button.
void Button::addText(std::string text, TTF_Font* font, SDL_Color textcolor, int offsetX, int offsetY)
{
    uint8_t font_size = TTF_FontHeight(font);
    // The text is displayed centered.
    label = new Label(text, font, (x + static_cast<int>(font_size / 2)) + offsetX, (y + static_cast<int>(font_size / 2)) + offsetY);
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
    uint8_t r = 0, g = 0, b = 0, a = 255;
    switch (state) {
        case State::IDLE:
            break;
        case State::HOVER:
            b = 255;
            break;
        case State::ACTIVE:
            g = 255;
            break;
    }

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_Rect rect {x, y, width, height};
    SDL_RenderDrawRect(renderer, &rect);

    if (label != nullptr) {
        label->draw(renderer);
    }
}