#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "interfaces/view.hpp"
#include "interfaces/command.hpp"
#include "interfaces/iowrapper.hpp"

#include "game.hpp"
#include "player_controller.hpp"
#include "enemies_controller.hpp"
#include "enemy_building_controller.hpp"

#include <vector>
#include <ctime>

class GameProcess{
  enum class GameState{
    AwaitPlayer,
    AwaitEnemy,
    AwaitBuilding,
    GameOver,
    Exit,
    Quit
  };

  public:
    GameProcess(Game* game, ViewInterface* view, CommandInterface* controller);
    GameProcess(Game* game, IOWrapperInterface* wrapper);
    ~GameProcess();
    void start();

  private:
    Game* game;
    GameState state;
    ViewInterface* view;
    CommandInterface* controller;
    PlayerController* player_controller;
    EnemiesController* enemies_controller;
    EnemyBuildingController* building_controller;
    clock_t last_move;
    bool timer();
    void change_state();
    void loop();
};
#endif // GAME_PROCESS_H
