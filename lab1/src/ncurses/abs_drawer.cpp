#include "../../include/ncurses/abs_drawer.hpp"

AbstractDrawer::AbstractDrawer(Game* game)
:game(game), win(nullptr){}

AbstractDrawer::~AbstractDrawer(){
  if (this->win){
    delwin(this->win);
  }
}

void AbstractDrawer::del_window(){
  if (this->win){
    delwin(this->win);
    this->win = nullptr;
  }
}

void AbstractDrawer::move(int y, int x){
  if (!this->win)
    return;
  mvwin(this->win, y, x);
  wrefresh(this->win);
}

void AbstractDrawer::create_window(int y, int x){
  if (!this->win){
    this->win = newwin(this->scr_height, this->scr_width, y, x);
    this->draw();
  }
}

int AbstractDrawer::get_width(){
    return this->scr_width;
}

int AbstractDrawer::get_height(){
    return this->scr_height;
}