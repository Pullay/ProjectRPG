#include "MapState.h"
#include "Game.h"
#include "Player.h"
#include "Sprite.h"
#include "utils.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <map>
#include <sstream>

MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
    map = new Map(20, 15);
    player = new Player("", Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
}

MapState::~MapState()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
}

void MapState::update(float deltaTime)
{
    SDL_Event event = stateManager->getEvent();
    movePlayerByInput(event.key);
}

void MapState::render(SDL_Renderer* renderer)
{
    renderMap(renderer);
    renderPlayer(renderer);
    renderTextBox(renderer);
}

void MapState::movePlayerByInput(SDL_KeyboardEvent event)
{
    if (event.repeat == 0) {
        if (event.keysym.scancode == SDL_SCANCODE_A) {
            player->move(-1, 0);
            player->setState(PlayerState::RIGHT);
        }
        if (event.keysym.scancode == SDL_SCANCODE_D) {
            player->move(1, 0);
            player->setState(PlayerState::LEFT);
        }
        if (event.keysym.scancode == SDL_SCANCODE_W) {
            player->move(0, -1);
            player->setState(PlayerState::UP);
        }
        if (event.keysym.scancode == SDL_SCANCODE_S) {
            player->setState(PlayerState::DOWN);
            player->move(0, 1);
        }
    }

    if (player->getX() < 0) {
        player->move(1, 0);
    }
    if (player->getX() > Game::WINDOW_WIDTH - 32) {
        player->move(-1, 0);
    }
    if (player->getY() < 0) {
        player->move(0, 1);
    }
    if (player->getY() > Game::WINDOW_HEIGHT - 32) {
        player->move(0, -1);
    }
}

void MapState::renderMap(SDL_Renderer* renderer)
{
    SDL_Texture* map_texture = IMG_LoadTexture(renderer, "assets/map_tiles.png");
    Sprite map_tileset(map_texture, {32, 32, 32, 32});
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            drawSprite(renderer, map_tileset, x * 32, y * 32);

            ++x;
            if (x >= map->getWidth()) {
                x = 0;
                ++y;

                if (y >= map->getHidth())
                    y = 0;
            }
        }
    }
    SDL_DestroyTexture(map_texture);
}

void MapState::renderPlayer(SDL_Renderer* renderer)
{
    std::map<PlayerState, SDL_Rect> clips;
    clips[PlayerState::UP] = {24, 0, 24, 32};
    clips[PlayerState::LEFT] = {24, 32, 24, 32};
    clips[PlayerState::DOWN] = {24, 64, 24, 32};
    clips[PlayerState::RIGHT] = {24, 96, 24, 32};
    SDL_Texture* player_texture = IMG_LoadTexture(renderer, "assets/player.png");
    Sprite player_sprite(player_texture);
    player_sprite.setRect(clips[player->getState()]);
    drawSprite(renderer, player_sprite, player->getX(), player->getY());
    SDL_DestroyTexture(player_texture);
}

void MapState::renderTextBox(SDL_Renderer* renderer)
{
    std::stringstream steam;
    steam << "Player x" << player->getX() << ":y" << player->getY();
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    drawText(renderer, {steam.str()}, font, {0, 0,0, 255}, {5, Game::WINDOW_HEIGHT - 15, 20 ,20});
    TTF_CloseFont(font);
}