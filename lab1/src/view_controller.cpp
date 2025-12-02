#include "../include/view_controller.hpp"
#include "../include/player.hpp"
#include "../include/player_mode.hpp"
#include "../include/enemy_build.hpp"
#include "../include/game_draw.hpp"

#include <vector>

ViewController::ViewController(GameField* field, Player* player, EnemyBuild* build, std::vector<Enemy*>* enemies){
  
  noecho();
  start_color();
  wclear(stdscr);
  
  this->field_drawer = new GameDraw(player, field, build, enemies);

  this->calc_coordinates();
  
  this->draw();
}

ViewController::~ViewController(){
  if (this->field_drawer)
    delete this->field_drawer;
}


void ViewController::draw(){
  if (!this->is_visible)
    return;
  this->field_drawer->draw();
  move(0, 0);
  wrefresh(stdscr);
}

void ViewController::del_windows(){
  if (this->is_visible){
    this->field_drawer->del_window();
    wclear(stdscr);
  }
}

void ViewController::create_windows(){
  this->field_drawer->create_window(this->field_y, this->field_x);
}

bool ViewController::calc_coordinates(){
  int row, col;

  getmaxyx(stdscr, row, col);
  
  if (this->row == row && this->col == col)
    return false;
  
  this->col = col;
  this->row = row;
  
  int field_width = this->field_drawer->get_width();
  int field_height = this->field_drawer->get_height();

  this->field_x = (col - field_width) / 2;
  this->field_y = (row - field_height) / 2;
  
  if (col < field_width + 5 || row < field_height + 5){
    if (this->is_visible){
      del_windows();
      this->is_visible = false;
    }
  } else {
      if (!this->is_visible){
      this->is_visible = true;
      this->create_windows();
    }
  }

  return true;
}

void ViewController::move_field(){
  wclear(stdscr);
  wrefresh(stdscr);
  this->field_drawer->move(this->field_y, this->field_x);
  move(0,0);
}

void ViewController::check_size(){
  if (this->calc_coordinates()){
    if (this->is_visible)
      this->move_field();
  }
}

void ViewController::invalidate(){
  this->check_size();
  this->draw();
}
