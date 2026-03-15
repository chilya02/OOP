#include "../../../include/common/ncurses/iowrapper.hpp"

#include "../../../include/inputs/ncurses/command_controller.hpp"
#include "../../../include/views/ncurses/view.hpp"

#include <ncurses.h>

NcursesIOWrapper::NcursesIOWrapper(Game* game){
  initscr();
  noecho();
  this->command = new NcursesCommandController();
  this->view = new NcursesView(game);
}

NcursesIOWrapper::~NcursesIOWrapper(){
  endwin();
  if (this->command)
    delete this->command;
  if (this->view)
    delete this->view;
}