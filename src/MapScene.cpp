#include "MapScene.h"
#include "utils.h"

#include <algorithm>
#include <cstdint>

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
}

bool MapScene::initialize()
{
    map = TileMap::create(20, 15, 32, MAP_TILESHEET_FILE, mapData);
    auto player_sprite = Sprite::load(PLAYER_SPRITESHEET_FILE);
    if(!player_sprite) {
        SDL_LogError(0, "%s:%d Unable to create a sprite", __FILE__, __LINE__);
        return false;
    }
    player = new Player("", player_sprite);
    player->setPosition({320.f, 240.f});
    spawnEnemies();
    return true;
}

void MapScene::update(const float& deltaTime)
{
    // movement player
    Input* input = this->getGame()->getInput();
    if(input->isKeyUp(SDLK_w)) {
        player->move(0.f, -1.f, deltaTime);
    }
    if(input->isKeyUp(SDLK_s)) {
        player->move(0.f, 1.f, deltaTime);
    }
    if(input->isKeyUp(SDLK_a)) {
        player->move(-1.f, 0.f, deltaTime);
    }
    if(input->isKeyUp(SDLK_d)) {
        player->move(1.f, 0.f, deltaTime);
    }

    // check collision
    for (auto enemy : enemies) {
        if (player->isColliding(enemy)) {
            player->resolveCollision(enemy);
            continue;
        }
    }

    SDL_FPoint pos;
    pos.x = std::min(std::max(player->getPosition().x, 0.f), static_cast<float>(map->getWidth() * map->getTileSize()) - 24);
    pos.y = std::min(std::max(player->getPosition().y, 0.f), static_cast<float>(map->getHeidth() * map->getTileSize()) - 32);
    player->setPosition(pos);
    player->getSprite()->setPosition(pos);
}

void MapScene::render(SDL_Renderer* renderer)
{
    // rendering map
    auto tile_size = map->getTileSize();
    SDL_Texture* tilesheet_texture = SDL_CreateTextureFromSurface(renderer, map->getTilesheetSurface());
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            uint16_t tilesheet_offset_x = tile.id * tile_size;
            uint16_t tilesheet_offset_y = tile.id * tile_size;
            //The offset along the axes cannot exceed the size of the tile sheet
            if (
              tilesheet_offset_x > map->getTilesheetSurface()->h
              || tilesheet_offset_y > map->getTilesheetSurface()->w
            ) {
                tilesheet_offset_x = 0;
                tilesheet_offset_y = 0;
            }
            SDL_Rect src{tilesheet_offset_x, tilesheet_offset_y, tile_size, tile_size};
            SDL_FPoint fposition{static_cast<float>(tile.position.x), static_cast<float>(tile.position.y)};
            blit(renderer, tilesheet_texture, src, fposition);
        }
    }
    SDL_DestroyTexture(tilesheet_texture);
    tilesheet_texture = nullptr;
    // rendering player
    player->getSprite()->render(renderer);
    // rendering enemies
    for (auto enemy : enemies) {
        enemy->getSprite()->render(renderer);
    }
}

// PRIVATE
void MapScene::spawnEnemies()
{
    auto sprite = Sprite::load(ENEMIES_SPRITESHEET_FILE);
    int i = 0;
    while (i < maxEnemies) {
        auto enemy = new Enemy(sprite);
        float x, y;
        x = static_cast<float>(map->getWidth());
        y = static_cast<float>(rand() % map->getHeidth());
        enemy->setPosition({x, y});
        enemy->getSprite()->setPosition({x, y});
        enemies.push_back(enemy);
        ++i;
    }
}