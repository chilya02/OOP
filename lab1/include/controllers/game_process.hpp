#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "../views/interfaces/view_interface.hpp"
#include "../inputs/interfaces/command_interface.hpp"
#include "../common/interfaces/iowrapper_interface.hpp"

#include "../models/game.hpp"

#include "player_controller.hpp"
#include "enemies_controller.hpp"
#include "enemy_building_controller.hpp"
#include "command_handler.hpp"

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
    CommandHandler* command_handler;
    EnemiesController* enemies_controller;
    EnemyBuildingController* building_controller;
    clock_t last_move;
    bool timer();
    void change_state();
    void loop();
};
#endif // GAME_PROCESS_H
