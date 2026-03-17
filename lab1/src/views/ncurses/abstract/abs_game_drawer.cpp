#include "../../../../include/views/ncurses/abstract/abs_game_drawer.hpp"

AbstractGameDrawer::AbstractGameDrawer(Game* game)
:AbstractDrawer(), game(game){}

AbstractGameDrawer::~AbstractGameDrawer(){
  if (this->win){
    delwin(this->win);
  }
}

void AbstractGameDrawer::del_window(){
  if (this->win){
    delwin(this->win);
    this->win = nullptr;
  }
}

void AbstractGameDrawer::create_window(int y, int x){
  if (!this->win){
    this->win = newwin(this->scr_height, this->scr_width, y, x);
    this->draw();
  }
}

int AbstractGameDrawer::get_width(){
    return this->scr_width;
}

int AbstractGameDrawer::get_height(){
    return this->scr_height;
}