#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "interfaces/view.hpp"
#include "interfaces/command.hpp"
#include "interfaces/iowrapper.hpp"

#include "game.hpp"

#include <vector>

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
    void loop();
};
#endif // GAME_PROCESS_H
