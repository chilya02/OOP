#include "../../include/controllers/menu_controller.hpp"

MenuController::MenuController(IMenu& menu, bool vertical)
  :menu(menu), vertical(vertical){}

MenuController::~MenuController(){}

bool MenuController::handle_command(Command command){
  if (this->vertical){
    switch (command){
      case Command::Up:
        this->menu.dec_index();
        return true;
        break;
      case Command::Down:
        this->menu.inc_index();
        return true;
        break;
      default:
        return false;
    }
  } else{
    switch (command){
      case Command::Left:
        this->menu.dec_index();
        return true;
        break;
      case Command::Right:
        this->menu.inc_index();
        return true;
        break;
      default:
        return false;
    }
  }
}