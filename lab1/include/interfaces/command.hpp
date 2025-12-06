#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include "../common/game_commands.hpp"

class CommandInterface{
  public:
    virtual ~CommandInterface(){};
    virtual Command get_command() = 0;
};
#endif //COMMAND_CONTROLLER_H