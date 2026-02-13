#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../models/menus/interfaces/menu_interface.hpp"
#include "../common/game_commands.hpp"

class MenuController{
  public:
    MenuController(IMenu&, bool = false);
    ~MenuController();
    virtual bool handle_command(Command command);
  protected:
    bool vertical;
    IMenu& menu;
};

#endif