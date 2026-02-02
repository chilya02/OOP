#ifndef WEAPON_H
#define WEAPON_H

#include "../config.hpp"
#include "player.hpp"
#include "../cells/game_field.hpp"
#include "weapon_direction.hpp"
#include "weapoon_mode.hpp"

class Weapon{
  public:
    Weapon(Player* player, GameField* field);
    ~Weapon();
    std::vector<Cell*> get_area();
    int get_damage();
    WeaponMode get_mode();
  private:
    int get_offset();
    WeaponDirection direction;
    WeaponMode mode;
    Player* player;
    GameField* field;
  friend class WeaponController;
};

#endif //WEAPON_H