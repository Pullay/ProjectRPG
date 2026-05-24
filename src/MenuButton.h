#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

class MenuButton final
{
    public:
        MenuButton(int x, int y, int w, int h);
        ~MenuButton();
        void addText(TTF_Font* font,  std::string text, SDL_Color textcolor);
        bool onHit(int mx, int my);
        SDL_Surface* getTextSurface();
        SDL_Rect getRect();

    private:
        int x, y;
        int w, h;
        SDL_Surface* textSurface;
};
#endif