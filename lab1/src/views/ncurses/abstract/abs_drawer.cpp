#include "../../../../include/views/ncurses/abstract/abs_drawer.hpp"


AbstractDrawer::AbstractDrawer():win(nullptr){

}

void AbstractDrawer::move(int y, int x){
  if (!this->win)
    return;
  mvwin(this->win, y, x);
  wrefresh(this->win);
}

