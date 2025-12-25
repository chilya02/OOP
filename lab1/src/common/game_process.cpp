#include "../../include/common/game_process.hpp"

#include <iostream>

GameProcess::GameProcess(Game* game, ViewInterface* view, CommandInterface* controller)
:game(game), view(view), controller(controller){
  this->enemies_controller = new EnemiesController(game->enemies, game->player, game->field, game->weapon);
  this->command_handler = new CommandHandler(game->player, game->weapon, game->spells_hand, enemies_controller);
  this->building_controller = new EnemyBuildingController(game->enemies, game->enemy_building);
}

GameProcess::GameProcess(Game* game, IOWrapperInterface* wrapper)
:GameProcess(game, wrapper->get_view(), wrapper->get_command()){}

GameProcess::~GameProcess(){
  if (this->building_controller)
    delete this->building_controller;
  if (this->enemies_controller)
    delete this->enemies_controller;
  if (this->command_handler)
    delete this->command_handler;
}

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
    if (!this->game->player->is_alive()){
      this->state = GameState::GameOver;
    }
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

        if (this->command_handler->handle_command(command))
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
