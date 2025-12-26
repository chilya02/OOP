#ifndef SPELL_CONTROLLER_INTERFACE_H
#define SPELL_CONTROLLER_INTERFACE_H

#include "../common/game_commands.hpp"

class SpellControllerInterface{
  public:
    virtual bool handle_command(Command command) = 0;
};

#endif //#SPELL_CONTROLLER_H