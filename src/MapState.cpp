#include "MapState.h"
#include "Game.h"
#include "Label.h"
#include "MapLoader.h"
#include "Player.h"
#include "utils.h"

#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

#include <iostream>
#include <map>
#include <sstream>

//TODO: This class has too many responsibilities.
//      It will need to be divided into several smaller ones.
MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
    map = MapLoader::load();
    player = new Player("", {Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2});
    spawnEnemies();
}

MapState::~MapState()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
    for (auto it : enemies) {
        delete it;
    }
    enemies.clear();
}

void MapState::update(const float& deltaTime)
{
    SDL_Event event = stateManager->getEvent();
    movePlayerByInput(event.key);
}

void MapState::render(SDL_Renderer* renderer)
{
    renderMap(renderer);
    renderPlayer(renderer);
    renderEnemies(renderer);
    renderTextBox(renderer);
}

// TODO: The movement system needs to be redesigned
void MapState::movePlayerByInput(SDL_KeyboardEvent event)
{
    if (stateManager->getEvent().type == SDL_KEYDOWN && event.repeat == 0) {
        switch (event.keysym.sym) {
            case SDLK_w:
                player->move(0, 1);
                player->setState(Player::WALK_UP);
                break;
            case SDLK_s:
                player->setState(Player::WALK_DOWN);
                player->move(0, -1);
                break;
            case SDLK_d:
                player->move(-1, 0);
                player->setState(Player::WALK_LEFT);
                break;
            case SDLK_a:
                player->move(1, 0);
                player->setState(Player::WALK_RIGHT);
                break;
        } 
    } else if (stateManager->getEvent().type == SDL_KEYUP && event.repeat == 0) {
        switch (event.keysym.sym) {
            case SDLK_w:
                player->move(0, -1);
                player->setState(Player::WALK_UP);
                break;
            case SDLK_s:
                player->setState(Player::WALK_DOWN);
                player->move(0, 1);
                break;
            case SDLK_d:
                player->move(1, 0);
                player->setState(Player::WALK_LEFT);
                break;
            case SDLK_a:
                player->move(-1, 0);
                player->setState(Player::WALK_RIGHT);
                break;
        }
    }
    
    if (player->getPosition().x > (Game::WINDOW_WIDTH - player->getCollider().w)) {
        player->move(-1, 0);
    }
    if (player->getPosition().y > (Game::WINDOW_HEIGHT - player->getCollider().h)) {
        player->move(0, -1);
    }

    for (auto enemy : enemies) {
        if (player->checkCollision(enemy)) {
            switch (player->getState()) {
                case Player::WALK_UP:
                    player->move(0, 1);
                    break;
                case Player::WALK_DOWN:
                    player->move(0, -1);
                    break;
                case Player::WALK_LEFT:
                    player->move(-1, 0);
                    break;
                case Player::WALK_RIGHT:
                    player->move(1, 0);
                    break;
                default:
                    break;
            }
        }
    }
}

void MapState::spawnEnemies()
{
    // spaw test enemy
    auto enemy = new Enemy("test", {(Game::WINDOW_WIDTH / 2) - 10, (Game::WINDOW_HEIGHT / 2) - 10});
    enemies.push_back(enemy);
}

void MapState::renderMap(SDL_Renderer* renderer)
{
    std::vector<SDL_Rect> tileset;
    tileset.push_back({0, 0, 32, 32});
    tileset.push_back({32, 32, 32, 32});
    SDL_Texture* map_texture = loadTexture(renderer, "assets/map_tiles.png");
    Sprite map_tileset(map_texture);
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            map_tileset.setRect(tileset[tile.id]);
            drawSprite(renderer, map_tileset, x * 32, y * 32);

            x++;
            if (x >= map->getWidth()) {
                x = 0;
                y++;

                if (y >= map->getHidth())
                    y = 0;
            }
        }
    }
    SDL_DestroyTexture(map_texture);
    map_texture = nullptr;
}

void MapState::renderPlayer(SDL_Renderer* renderer)
{
    // Hitbox display
    displayHitBox(renderer, player);

    std::map<Player::State, SDL_Rect> clips;
    clips[Player::IDLE] = {24, 64, 24, 32};
    clips[Player::WALK_UP] = {24, 0, 24, 32};
    clips[Player::WALK_LEFT] = {24, 32, 24, 32};
    clips[Player::WALK_DOWN] = {24, 64, 24, 32};
    clips[Player::WALK_RIGHT] = {24, 96, 24, 32};
    SDL_Texture* player_texture = loadTexture(renderer, "assets/player.png");
    Sprite player_sprite(player_texture);
    player_sprite.setRect(clips[player->getState()]);
    drawSprite(renderer, player_sprite, player->getPosition().x, player->getPosition().y);
    SDL_DestroyTexture(player_texture);
    player_sprite = nullptr;
}

void MapState::renderEnemies(SDL_Renderer* renderer)
{
    if (enemies.empty()) {
        return;
    }

    // TODO: temp texture
    SDL_Texture* enemy_texture = loadTexture(renderer, "assets/player.png");
    Sprite enemy_sprite(enemy_texture, {24, 64, 24, 32});
    TTF_Font* font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    for (auto enemy : enemies) {
        
        Label label(enemy->getName(), font, enemy->getPosition().x, enemy->getPosition().y - 16);
        label.draw(renderer);
        // Hitbox display
        displayHitBox(renderer, enemy);
        drawSprite(renderer, enemy_sprite, enemy->getPosition().x, enemy->getPosition().y);
    }
    SDL_DestroyTexture(enemy_texture);
    enemy_texture = nullptr;
    TTF_CloseFont(font);
    font = nullptr;
}

void MapState::renderTextBox(SDL_Renderer* renderer)
{
    std::stringstream steam;
    steam << "Player x" << player->getPosition().x << ":y" << player->getPosition().y;
    TTF_Font* font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    Label label({steam.str()}, font, 5, Game::WINDOW_HEIGHT - 15);
    label.setColor({0, 0, 0, 255});
    label.draw(renderer);
    TTF_CloseFont(font);
    font = nullptr;
}

void MapState::displayHitBox(SDL_Renderer* renderer, GameObject* object)
{
    if (!object) {
        return;
    }

    SDL_Rect hitbox = object->getCollider();
    SDL_RenderDrawRect(renderer, &hitbox);
}