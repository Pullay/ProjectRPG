#include "MapScene.h"
#include "TempMapData.h"

MapScene::MapScene()
{
    initialize();
}

MapScene::~MapScene()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
    delete movementSystem;
    movementSystem = nullptr;
    delete mapView;
    mapView = nullptr;
    delete spriteView;
    spriteView = nullptr;
}

bool MapScene::initialize()
{
    map = TileMap::load(new TempMapData());
    auto player_sprite = Sprite::load(PLAYER_SPRITESHEET_FILE);
    if(!player_sprite) {
        SDL_LogError(0, "%s:%d Unable to create a sprite", __FILE__, __LINE__);
        return false;
    }
    player = new Player("", player_sprite);
    player->setPosition({320.f, 240.f});
    // systems
    movementSystem = new MovementSystem(*map, *player);
    //
    mapView = new TileMapView(*map);
    spriteView = new SpriteView();
    spriteView->add(player_sprite);
    return true;
}

void MapScene::update(const float& deltaTime)
{
    // movement player
    Input* input = this->getGame()->getInput();
    if(input->isKeyUp(SDLK_w)) {
        movementSystem->move(0.f, -1.f);
    }
    if(input->isKeyUp(SDLK_s)) {
        movementSystem->move(0.f, 1.f);
    }
    if(input->isKeyUp(SDLK_a)) {
        movementSystem->move(-1.f, 0.f);
    }
    if(input->isKeyUp(SDLK_d)) {
        movementSystem->move(1.f, 0.f);
    }
    movementSystem->update(deltaTime);
}

void MapScene::render(SDL_Renderer* renderer)
{
    mapView->render(renderer);
    spriteView->render(renderer);
}
