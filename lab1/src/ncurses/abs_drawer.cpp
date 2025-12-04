#include "../../include/ncurses/abs_drawer.hpp"

AbstractDrawer::AbstractDrawer()
:win(nullptr){}

void AbstractDrawer::del_window(){
  if (this->win)
    delwin(this->win);
}