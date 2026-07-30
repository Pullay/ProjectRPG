#ifndef GAME_H_
#define GAME_H_

#include "Input.h"

#include <SDL.h>

#include <cstdint>
#include <string>

class BaseScene;

// Linked List Class​​ @source https://www.compilenrun.com/docs/language/cpp/cpp-advanced-data-structures/cpp-linked-lists/
class Game final
{
    public:
        Game(std::string title, uint16_t width, uint16_t height);
        ~Game();
        bool initialize();
        SDL_Window* getWindow();
        Input* getInput() const;
        void pushScene(BaseScene* scene);
        bool popScene();
        void run();
        void quit();

    private:
        SDL_Window* window;
        Input* input;
        bool running = false;
        BaseScene* head;
  
        SDL_Window* createWindow(std::string title, uint16_t width, uint16_t height);
};
#endif