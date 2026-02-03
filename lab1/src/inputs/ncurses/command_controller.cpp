#include "../../../include/inputs/ncurses/command_controller.hpp"

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
    case 'f':
      return Command::Attack;
    case 'r':
      return Command::ChangeRange;
    case 'm':
      return Command::Move;
    case 'c':
      return Command::Cast;
    case KEY_UP:
    case 'w':
      return Command::Up;
    case KEY_DOWN:
    case 's':
      return Command::Down;
    case KEY_RIGHT:
    case 'd':
      return Command::Right;
    case KEY_LEFT:
    case 'a':
      return Command::Left;
    case '\n':
    case '\r':
    case KEY_ENTER:
      return Command::Ok;
    }
    return Command::Undefined;
}