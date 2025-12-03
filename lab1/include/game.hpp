#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "game_field.hpp"
#include "player_controller.hpp"
#include "enemy_build.hpp"
#include "enemies_controller.hpp"
#include "enemy.hpp"

#include <vector>

class Game{
  public:
    Game(int height = 10, int width = 10, int period = 3);
    ~Game();
    static Game* create_random_game();
    static Game* create_user_game();
    GameField* field;
    Player* player;
    EnemyBuild* enemy_build;
    PlayerController* player_controller;
    EnemiesController* enemies_controller;
    std::vector<Enemy*>* enemies;
};

#endif //GAME_H