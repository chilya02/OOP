#include "../include/game_process.hpp"


#include <iostream>
#include <ctime>

GameProcess::GameProcess(Game* game, ViewInterface* view, CommandInterface* controller)
:game(game), view(view), controller(controller){}


GameProcess::GameProcess(Game* game, IOWrapperInterface* wrapper)
:game(game), view(wrapper->get_view()), controller(wrapper->get_command()){}

GameProcess::~GameProcess(){}



void GameProcess::start(){
  if (!(game->player) || !(game->field)){
    std::cerr << "Game has not configurated" << std::endl;
    exit(0);
  }

  state = GameState::AwaitPlayer;
  loop();
}

void GameProcess::loop(){
  Command command;

  view->invalidate();
  unsigned last_time = clock();
  while (state != GameState::Exit){

    command = controller->get_command();
    if (command == Command::Quit)
      state = GameState::Quit;

    view->check_size();

    switch (state){

      case GameState::AwaitPlayer:

        if (game->player_controller->handle_command(command))
          view->invalidate();

        if (!game->player->can_act()){
          last_time = clock();
          state = GameState::AwaitEnemy;
        }

        break;

      case GameState::AwaitEnemy:

        if ((clock() - last_time) >= 1000000){
          game->enemies_controller->act();
          state = GameState::AwaitPlayer;
          game->player->change_status();
          view->invalidate();
        }

        break;

      case GameState::AwaitBuilding:
        
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
