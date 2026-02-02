#include "../../include/controllers/weapon_controller.hpp"

WeaponController::WeaponController(Weapon* weapon)
:weapon(weapon){
  
}

WeaponController::~WeaponController(){}

int WeaponController::get_damage(){
  return this->weapon->get_damage();
}

std::vector<Cell*> WeaponController::get_area(){
  return this->weapon->get_area();
}

bool WeaponController::handle_command(Command command){
  switch (command){
    case Command::Up:
      this->weapon->direction = WeaponDirection::Top;
      return true;
      break;
    case Command::Down:
      this->weapon->direction = WeaponDirection::Bottom;
      return true;
      break;
    case Command::Left:
      this->weapon->direction = WeaponDirection::Left;
      return true;
      break;
    case Command::Right:
      this->weapon->direction = WeaponDirection::Right;
      return true;
      break;
    case Command::Ok:
      return true;
    default:
      return false;
  }
}