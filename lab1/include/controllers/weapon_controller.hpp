#ifndef WEAPON_CONTROLLER_H
#define WEAPON_CONTROLLER_H

#include "../cell_objects/weapon.hpp"
#include "../common/game_commands.hpp"

class WeaponController{
  public:
    WeaponController(Weapon* );
    ~WeaponController();
    std::vector<Cell*> get_area();
    int get_damage();
    bool handle_command(Command);
    bool change_mode();
  private:
    Weapon* weapon;
};

#endif // WEAPON_CONTROLLER_H