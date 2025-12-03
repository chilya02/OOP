#include "../include/game_process.hpp"


#include <iostream>
#include <ctime>

GameProcess::GameProcess(Game* game, ViewInterface* view, CommandInterface* controller)
:game(game), view(view), controller(controller){
  this->player_controller = new PlayerController(game->player);
  this->enemies_controller = new EnemiesController(game->enemies, game->player, game->field);
  this->building_controller = new EnemyBuildingController(game->enemies, game->enemy_building);
}

GameProcess::GameProcess(Game* game, IOWrapperInterface* wrapper)
:GameProcess(game, wrapper->get_view(), wrapper->get_command()){}

GameProcess::~GameProcess(){}

void GameProcess::start(){
  if (!(game->player) || !(game->field)){
    std::cerr << "Game has not configurated" << std::endl;
    exit(0);
  }

  state = GameState::AwaitPlayer;
  loop();
}

void GameProcess::change_state(){
  switch (this->state){
  case GameState::AwaitPlayer:
    this->state = GameState::AwaitEnemy;
    break;
  case GameState::AwaitEnemy:
    this->state = GameState::AwaitBuilding;
    break;
  case GameState::AwaitBuilding:
    this->state = GameState::AwaitPlayer;
    this->game->player->change_status();
    break;
  case GameState::Quit:
  case GameState::Exit:
  case GameState::GameOver:
    break;
  }
  this->last_move = clock();
}

bool GameProcess::timer(){
   return ((float)(clock() - last_move))/CLOCKS_PER_SEC >= 0.3;
}

void GameProcess::loop(){
  Command command;

  view->invalidate();
  while (state != GameState::Exit){

    command = controller->get_command();
    if (command == Command::Quit)
      state = GameState::Quit;

    view->check_size();

    switch (state){

      case GameState::AwaitPlayer:

        if (this->player_controller->handle_command(command))
          view->invalidate();

        if (!game->player->can_act()){
          this->change_state();
        }

        break;

      case GameState::AwaitEnemy:

        if (this->timer()){
          this->enemies_controller->act();
          this->change_state();
          view->invalidate();
        }

        break;

      case GameState::AwaitBuilding:
          this->building_controller->act();
          this->change_state();
          view->invalidate();
        break;

      case GameState::Quit:

        state = GameState::Exit;
        break;  
      
      case GameState::GameOver:
        break;
      case GameState::Exit:
        break;
    }
  }
}
