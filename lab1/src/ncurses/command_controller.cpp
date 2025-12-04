#include "../../include/ncurses/command_controller.hpp"

#include <ncurses.h>

NcursesCommandController::NcursesCommandController(){
  keypad(stdscr, 1);  
  nodelay(stdscr, 1);
}

NcursesCommandController::~NcursesCommandController(){}

Command NcursesCommandController::get_command(){
  int command = '\0';
  command = getch();

  switch (command) {
    case 'q':
      return Command::Quit;
    case 'a':
      return Command::Attack;
    case KEY_UP:
      return Command::Up;
    case KEY_DOWN:
      return Command::Down;
    case KEY_RIGHT:
      return Command::Right;
    case KEY_LEFT:
      return Command::Left;
    }
    return Command::Undefined;
}