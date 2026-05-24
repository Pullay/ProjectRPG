#include "MenuButton.h"

MenuButton::MenuButton(int x, int y, int w, int h)
  : x(x)
  , y(y)
  , w(w)
  , h(h)
{}

MenuButton::~MenuButton()
{
    SDL_FreeSurface(textSurface);
}

void MenuButton::addText(TTF_Font* font,  std::string text, SDL_Color textcolor)
{
    textSurface = TTF_RenderText_Solid(font, text.c_str(), textcolor);
}

bool MenuButton::onHit(int mx, int my)
{
    if (mx >= x && mx < x + w && my >= y && my < y + h) {
        return true;
    }
    return false;
}

SDL_Rect MenuButton::getRect()
{
    return SDL_Rect{x, y, w, h};
}

SDL_Surface* MenuButton::getTextSurface()
{
    return textSurface;
}