#include "../../include/controllers/weapon_controller.hpp"

WeaponController::WeaponController(Weapon* weapon)
:MovableDamageController(weapon), weapon(weapon){
  
}


void WeaponController::set_center(){
  this->weapon->center();
}