#include "IntroScene.h"

IntroScene::IntroScene()
{
    nextScene = new MainMenuScene();
}

IntroScene::~IntroScene()
{
    delete nextScene;
    nextScene = nullptr;
}

void IntroScene::update(const float& deltaTime)
{
    this->setNext(nextScene);
}

void IntroScene::render(SDL_Renderer* renderer)
{}