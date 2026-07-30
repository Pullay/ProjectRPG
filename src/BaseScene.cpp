#include "BaseScene.h"

void BaseScene::setNext(BaseScene* scene)
{
    next = scene;
}

BaseScene* BaseScene::getNext()
{
    return next;
}

void BaseScene::handleGame(Game* game)
{
    this->game = game;
}

Game* BaseScene::getGame()
{
    return game;
}