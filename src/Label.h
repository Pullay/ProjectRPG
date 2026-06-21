#ifndef LABEL_H_
#define LABEL_H_

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

class Label
{
    public:
        Label(std::string text, TTF_Font* font, int x, int y);
        int getX() const;
        int getY() const;
        std::string getText() const;
        TTF_Font* getFont() const;
        void setColor(SDL_Color color);
        SDL_Color getColor() const;
        void draw(SDL_Renderer* renderer);

    private:
        int x, y;
        std::string text;
        TTF_Font* font;
        SDL_Color textcolor;
};
#endif
