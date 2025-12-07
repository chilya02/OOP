#ifndef WEAPON_CONTROLLER_H
#define WEAPON_CONTROLLER_H

#include "../cell_objects/weapon.hpp"
#include "movable_controller.hpp"

class WeaponController: public MovableController{
  public:
    WeaponController(Weapon* );
    bool handle_command(Command command);
    void set_center();
  private:
    Weapon* weapon;
};

#endif // WEAPON_CONTROLLER_H