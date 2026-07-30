#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
    nextScene = new MapScene();
}

MainMenuScene::~MainMenuScene()
{
    delete nextScene;
    nextScene = nullptr;
}

void MainMenuScene::update(const float& deltaTime)
{
    this->setNext(nextScene);
}

void MainMenuScene::render(SDL_Renderer* renderer)
{}