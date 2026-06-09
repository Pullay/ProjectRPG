#include "Label.h"
#include "utils.h"

Label::Label(std::string text, TTF_Font* font, int x, int y)
  : text(text)
  , font(font)
  , x(x)
  , y(y)
{
    textcolor = {255, 255, 255, 255};
}

int Label::getX() const
{
    return x;
}

int Label::getY() const
{
    return y;
}

std::string Label::getText()
{
    return text;
}

TTF_Font* Label::getFont()
{
    return font;
}

void Label::setColor(SDL_Color color)
{
    textcolor = color;
}

SDL_Color Label::getColor()
{
    return textcolor;
}

void Label::draw(SDL_Renderer* renderer)
{
    drawText(renderer, text, font, textcolor, x, y);
}
