#ifndef NCURSES_COMMAND_CONTROLLER_H
#define NCURSES_COMMAND_CONTROLLER_H

#include "../interfaces/command.hpp"

class NcursesCommandController final:public CommandInterface{
  public:
    NcursesCommandController();
    virtual ~NcursesCommandController() final;
    Command get_command();
};
#endif //COMMAND_CONTROLLER_H