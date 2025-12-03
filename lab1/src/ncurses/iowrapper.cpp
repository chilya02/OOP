#include "../../include/ncurses/iowrapper.hpp"

#include "../../include/ncurses/command_controller.hpp"
#include "../../include/ncurses/view_controller.hpp"

#include <ncurses.h>

NcursesIOWrapper::NcursesIOWrapper(Game* game){
  initscr();
  noecho();
  this->command = new NcursesCommandController();
  this->view = new NcursesViewController(game);
}

NcursesIOWrapper::~NcursesIOWrapper(){
  endwin();
  if (this->command)
    delete this->command;
  if (this->view)
    delete this->view;
}