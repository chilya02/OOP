#ifndef WEAPON_CONTROLLER_H
#define WEAPON_CONTROLLER_H

#include "../cell_objects/weapon.hpp"
#include "movable_damage_controller.hpp"

class WeaponController: public MovableDamageController{
  public:
    WeaponController(Weapon* );
    void set_center();
  private:
    Weapon* weapon;
};

#endif // WEAPON_CONTROLLER_H