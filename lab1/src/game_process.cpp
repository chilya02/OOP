#include "game_process.hpp"
#include "entity_status.hpp"
#include "game_field.hpp"
#include "game_view.hpp"
#include "command_controller.hpp"
#include "game_commands.hpp"

#include <iostream>
#include <ctime>

GameProcess::GameProcess(){
  this->player = nullptr;
  this->field = nullptr;
  this->contrroller = nullptr;
  this->player_controller = nullptr;
}

GameProcess::~GameProcess(){
  endwin();
}

void GameProcess::create_random_game(){
  srand(time(NULL));
  int size = 10 + rand() % 16;
  this->create_game(size, size);
}

void GameProcess::create_user_game(){
    std::cout << "Enter field height" << std::endl;
    int height;
    std::cin >> height;
    std::cout << "Enter field width" << std::endl;
    int width;
    std::cin >> width;
    this->create_game(width, height);
}

void GameProcess::create_game(int width, int height, int period){
  try{  
    this->field = new GameField(height, width, period);
    this->player = new Player();
  }
  catch (const char* error_msg){
    std::cerr << error_msg << std::endl;
    exit(0);
  }
}

void GameProcess::start(){
  if (!(this->player) || !(this->field)){
    std::cerr << "Game has not configurated" << std::endl;
    exit(0);
  }
  Cell* player_cell = &(*this->field->cells[this->field->height - 1][this->field->width - 1]);
  this->player_controller = new PlayerController(this->player, player_cell);
  this->contrroller = new CommandController();
  this->view = new GameView(this->field, this->player);
  
  this->state = GameState::AwaitPlayer;
  this->loop();
}

void GameProcess::loop(){
  Command command;

  this->view->invalidate();
  unsigned last_time = clock();
  while (this->state != GameState::Exit){

    command = this->contrroller->get_command();
    if (command == Command::Quit)
      this->state = GameState::Quit;

    this->view->check_size();

    switch (this->state){
      case GameState::AwaitPlayer:
        if (this->player_controller->handle_command(command)){
          last_time = clock();
          this->state = GameState::AwaitEnemy;
          this->view->invalidate();
        }
        break;
      case GameState::AwaitEnemy:
        if ((clock() - last_time) >= 100000){
          this->state = GameState::AwaitPlayer;
          this->player->change_status();
          this->view->invalidate();
        }
        break;
      case GameState::Quit:
        this->state = GameState::Exit;
        break;  
      case GameState::GameOver:
        break;
      case GameState::Exit:
        break;
    }
  }
}
