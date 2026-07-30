#ifndef MAINMENUSCENE_H_
#define MAINMENUSCENE_H_

#include "BaseScene.h"
#include "MapScene.h"

class MainMenuScene final : public BaseScene
{
    public:
        MainMenuScene();
        ~MainMenuScene() override;
        void update(const float& deltaTime) override;
        void render(SDL_Renderer* renderer) override;

    private:
        MapScene* nextScene;
};
#endif