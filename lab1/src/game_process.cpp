#include "game_process.hpp"
#include "entity_status.hpp"
#include "game_field.hpp"
#include "game_view.hpp"

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <ctime>

GameProcess::GameProcess(){
  this->player = NULL;
  this->field = NULL;
}
GameProcess::~GameProcess(){
  endwin();
}

void GameProcess::create_random_game(){
  srand(time(NULL));
  int size = 10 +  rand() % 16;
  this->player = new Player();
  this->field = new GameField(size, size);
}

void GameProcess::create_user_game(){
  try{
    std::cout << "Enter field height" << std::endl;
    int height;
    std::cin >> height;
    std::cout << "Enter field width" << std::endl;
    int width;
    std::cin >> width;
    this->field = new GameField(height, width);
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
  this->set_player_pos();    
  initscr();
  keypad(stdscr, 1);  
  nodelay(stdscr, 1);
  this->view = new GameView(this->field, this->player);
  this->state = GameState::AwaitPlayer;
  this->loop();
}

void GameProcess::set_player_pos(){
  this->player->cell = &(*this->field->cells[this->field->height - 1][this->field->width - 1]);
}

void GameProcess::move_player(int command){
  switch (command){
    case KEY_UP:
      this->player->move_up();
      break;
    case KEY_DOWN:
      this->player->move_down();
      break;
    case KEY_RIGHT:
      this->player->move_right();
      break;
    case KEY_LEFT:
      this->player->move_left();
      break;
  }
}
  
void GameProcess::loop(){
  int command = '\0';

  this->view->invalidate();
  time_t last_time;

  while (this->state != GameState::GameOver){

    command = getch();
    if (command == 'q')
      this->state = GameState::GameOver;

    switch (this->state){

      case GameState::AwaitPlayer:
        this->move_player(command);
        break;

      case GameState::AwaitEnemy:
        if ((time(0) - last_time) > 1){
          this->state = GameState::AwaitPlayer;
          this->player->status = EntityStatus::Await;
          this->view->invalidate();
        }
        break;

      case GameState::GameOver:
        break;
    }
    if (this->player->status == EntityStatus::Await)
      continue;
    this->view->invalidate();
    if (this->state == GameState::AwaitPlayer){
      this->state = GameState::AwaitEnemy;
      last_time = time(0);
    }
    //sleep(1);
    //this->player->status = EntityStatus::Await;
    //this->view->invalidate();
  }
}
