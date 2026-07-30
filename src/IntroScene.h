#ifndef INTROSCENE_H_
#define INTROSCENE_H_

#include "BaseScene.h"
#include "MainMenuScene.h"

class IntroScene final : public BaseScene
{
    public:
        IntroScene();
        ~IntroScene() override;
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        MainMenuScene* nextScene;
};
#endif