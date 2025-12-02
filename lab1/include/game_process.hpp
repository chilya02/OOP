#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "view_controller.hpp"
#include "player.hpp"
#include "game_field.hpp"
#include "command_controller.hpp"
#include "game_commands.hpp"
#include "player_controller.hpp"
#include "enemy_build.hpp"
#include "enemy.hpp"
#include "enemies_controller.hpp"
#include <vector>

class GameProcess{
  enum class GameState{
    AwaitPlayer,
    AwaitEnemy,
    AwaitBuild,
    GameOver,
    Exit,
    Quit
  };

  public:
    GameProcess();
    ~GameProcess();
    void create_user_game();
    void create_random_game();
    void create_game(int height=10, int width=10, int period=3);
    void start();

  private:
    GameField* field;
    Player* player;
    EnemyBuild* enemy_build;
    ViewController* view;
    CommandController* contrroller;
    PlayerController* player_controller;
    EnemiesController* enemies_controller;
    std::vector<Enemy*>* enemies;
    GameState state;
    void loop();
};
#endif // GAME_PROCESS_H
