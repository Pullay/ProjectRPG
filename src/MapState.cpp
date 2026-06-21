#include "MapState.h"
#include "Game.h"
#include "Label.h"
#include "MapLoader.h"
#include "utils.h"

#include <SDL_ttf.h>

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

void MapState::movePlayerByInput(SDL_KeyboardEvent event)
{
    if (event.repeat == 0) {
        if (event.keysym.scancode == SDL_SCANCODE_A) {
            player->move(-1, 0);
            player->setState(Player::WALK_RIGHT);
        }
        if (event.keysym.scancode == SDL_SCANCODE_D) {
            player->move(1, 0);
            player->setState(Player::WALK_LEFT);
        }
        if (event.keysym.scancode == SDL_SCANCODE_W) {
            player->move(0, -1);
            player->setState(Player::WALK_UP);
        }
        if (event.keysym.scancode == SDL_SCANCODE_S) {
            player->setState(Player::WALK_DOWN);
            player->move(0, 1);
        }
    }

    if (player->getPosition().x < 0) {
        player->move(1, 0);
    }
    if (player->getPosition().x > Game::WINDOW_WIDTH - 32) {
        player->move(-1, 0);
    }
    if (player->getPosition().y < 0) {
        player->move(0, 1);
    }
    if (player->getPosition().y > Game::WINDOW_HEIGHT - 32) {
        player->move(0, -1);
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

    // temp texture
    SDL_Texture* enemy_texture = loadTexture(renderer, "assets/player.png");
    Sprite enemy_sprite(enemy_texture, {24, 64, 24, 32});
    TTF_Font* font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    for (auto enemy : enemies) {
        Label label(enemy->getName(), font, enemy->getPosition().x, enemy->getPosition().y - 10);
        label.draw(renderer);
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