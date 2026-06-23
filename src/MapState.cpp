#include "MapState.h"
#include "Game.h"
#include "Label.h"
#include "MapLoader.h"
#include "utils.h"

#include <map>
#include <sstream>
#include <string>

//TODO: This class has too many responsibilities.
//      It will need to be divided into several smaller ones.
MapState::MapState(StateManager* stateManager) : stateManager(stateManager)
{
    font = loadFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
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
    if (font != nullptr) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

void MapState::update(const float& deltaTime)
{
    SDL_Event event = stateManager->getEvent();
    movePlayerByInput(event.key);
}

void MapState::render(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    renderMap();
    renderPlayer();
    renderEnemies();
    _displayDebugInfo();
}

// PRIVATE

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
    auto enemy = new Enemy("test", {(Game::WINDOW_WIDTH / 2) - 50, (Game::WINDOW_HEIGHT / 2) - 50});
    enemies.push_back(enemy);
}

void MapState::renderMap()
{
    int8_t tile_size = 32;
    std::vector<SDL_Rect> tileset;
    tileset.push_back({0, 0, tile_size, tile_size});
    tileset.push_back({32, 32, tile_size, tile_size});
    SDL_Texture* map_texture = loadTexture(renderer, "assets/map_tiles.png");
    int x = 0, y = 0;
    for (auto layer : map->getLayers()) {
        for (auto tile : layer.tiles) {
            // Don't draw tiles outside the window
            if ((x * tile_size) > Game::WINDOW_WIDTH && (y * tile_size) > Game::WINDOW_HEIGHT) {
                continue;
            }

            SDL_Rect src = tileset[tile.id];
            SDL_Rect dst{x * tile_size, y* tile_size, src.w, src.h};
            SDL_RenderCopy(renderer, map_texture, &src, &dst);

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

void MapState::renderPlayer()
{
    _displayHitBox(player);

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

void MapState::renderEnemies()
{
    if (enemies.empty()) {
        return;
    }

    // TODO: temp texture
    SDL_Texture* enemy_texture = loadTexture(renderer, "assets/player.png");
    Sprite enemy_sprite(enemy_texture, {24, 64, 24, 32});
    for (auto enemy : enemies) {
        Label label(enemy->getName(), font, enemy->getPosition().x, enemy->getPosition().y - 16);
        label.draw(renderer);
        _displayHitBox(enemy);
        drawSprite(renderer, enemy_sprite, enemy->getPosition().x, enemy->getPosition().y);
    }

    SDL_DestroyTexture(enemy_texture);
    enemy_texture = nullptr;
}

void MapState::drawLabel(std::string text, int x, int y)
{
    Label label(text, font, x, y);
    label.setColor({0, 0, 0, 255});
    label.draw(renderer);
}

void MapState::_displayDebugInfo()
{
    std::stringstream ss_player_position;
    ss_player_position<< "Player x" << player->getPosition().x << ":y" << player->getPosition().y;
    drawLabel(ss_player_position.str(), 5, Game::WINDOW_HEIGHT - 15);
}

void MapState::_displayHitBox(GameObject* object)
{
    if (!object) {
        return;
    }

    SDL_Rect hitbox = object->getCollider();
    SDL_RenderDrawRect(renderer, &hitbox);
}