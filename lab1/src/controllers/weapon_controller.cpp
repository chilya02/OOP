#include "../../include/controllers/weapon_controller.hpp"

WeaponController::WeaponController(Weapon* weapon)
:MovableController(weapon), weapon(weapon){
  
}
bool WeaponController::handle_command(Command command){
  if (this->move_obj(command)){
    return true;
  }
  if (command == Command::Ok){
    if (weapon->get_cell() == weapon->player->get_cell())
      return false;
    return true;
  }
  return false;
}

void WeaponController::set_center(){
  this->weapon->center();
}