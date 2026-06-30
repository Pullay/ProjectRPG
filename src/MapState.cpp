#include "Game.h"
#include "MapState.h"
#include "MapLoader.h"
#include "Player.h"
#include "utils.h"

#include <iostream>
#include <sstream>

MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
    initialize();
}

MapState::~MapState()
{
    if (font != nullptr) {
        TTF_CloseFont(font);
        font = nullptr;
    }

    delete map;
    map = nullptr;
    delete _playerSprite;
    _playerSprite = nullptr;
    delete player;
    player = nullptr;

    for (auto it: enemies) {
        delete it;
    }
    
}

bool MapState::initialize()
{
    font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    std::cerr << "Load file /usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf \n"; // INFO
    map = MapLoader::load();
    // Init Player
    _playerSprite = Sprite::load("assets/player.png");
    _playerSprite->setClip({24, 32, 24, 32}); // default clip
    player = new Player("Me", _playerSprite);
    player->addClip(Player::WALK_UP, {24, 0, 24, 32});
    player->addClip(Player::WALK_LEFT, {24, 32, 24, 32});
    player->addClip(Player::WALK_DOWN, {24, 64, 24, 32});
    player->addClip(Player::WALK_RIGHT, {24, 96, 24, 32});
    player->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
    // Init Enemies
    // TODO: temp sprite
    auto enemy = new Enemy("test", _playerSprite);
    enemy->setPosition(player->getPosition().x + 50, player->getPosition().y + 50);
    enemies.push_back(enemy);
    return true;
};

void MapState::update(const float& deltaTime)
{
    if (!map || !player) {
        std::cerr << __func__ << ": Access to the null pointer is not possible\n";
        return;
    }

    map->update(deltaTime);

    SDL_Event event = stateManager->getEvent();
    // movement player
    if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                player->move(Player::MoveDirection::UP);
                break;
            case SDLK_s:
                player->move(Player::MoveDirection::DOWN);
                break;
            case SDLK_a:
                player->move(Player::MoveDirection::LEFT);
                break;
            case SDLK_d:
                player->move(Player::MoveDirection::RIGHT);
                break;
        }
    }

    player->update(deltaTime);

    if (player->getPosition().x < 0
     || player->getPosition().x >= (map->getWidth() * map->getTileSize()) - 32
     || player->getPosition().y < 0
     || player->getPosition().y >= (map->getHidth() * map->getTileSize()) -32
    ) {
        player->moveBackward();
    }

    // update enemies
    for (auto enemy : enemies) {
        // check collsion
        if (player->isTouching(enemy)) {
            player->moveBackward();
        }

        enemy->update(deltaTime);
    }
}

void MapState::render(SDL_Renderer* renderer)
{
    if (!map || !player) {
        std::cerr << __func__ << ": Access to the null pointer is not possible\n";
        return;
    }

    map->render(renderer);
     _displayCollisionBox(renderer, player);
    player->render(renderer);

    for (auto enemy : enemies) {
        drawText(renderer, enemy->getName(), font, {0, 0, 0, 255}, enemy->getPosition().x, enemy->getPosition().y - 14);
        _displayCollisionBox(renderer, enemy);
        enemy->render(renderer);
    }
    _displayDebugInfo(renderer);
}

// PRIVATE
void MapState::_displayCollisionBox(SDL_Renderer* renderer, GameObject* object)
{
    if (!object) {
        std::cerr << ": There is no object to render \n";
        return;
    }

    SDL_Rect hitbox = object->getCollider();
    SDL_RenderDrawRect(renderer, &hitbox);
}

void MapState::_displayDebugInfo(SDL_Renderer* renderer)
{
    if (!player) {
        std::cerr << __func__ << ": Access to the null pointer is not possible\n";
        return;
    }

    std::stringstream ss_player_position;
    ss_player_position<< "Player x" << player->getPosition().x << ":y" << player->getPosition().y;
    drawText(renderer, ss_player_position.str(), font, {0, 0, 0, 255}, 5, Game::WINDOW_HEIGHT - 15);
}
