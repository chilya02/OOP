#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include "game_commands.hpp"

class CommandController{
  public:
    CommandController();
    Command get_command();
};
#endif //COMMAND_CONTROLLER_H