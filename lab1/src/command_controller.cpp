#include "../include/command_controller.hpp"

#include <ncurses.h>

#include "../include/game_commands.hpp"

CommandController::CommandController(){
  initscr();
  keypad(stdscr, 1);  
  nodelay(stdscr, 1);
}

Command CommandController::get_command(){
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