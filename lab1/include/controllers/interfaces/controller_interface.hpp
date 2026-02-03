#ifndef CONTROLLER_INTERFACE_H
#define CONTROLLER_INTERFACE_H

#include "../../common/game_commands.hpp"

class ControllerInterface{
  public:
    virtual bool handle_command(Command command) = 0;
};

#endif //CONTROLLER_INTERFACE_H