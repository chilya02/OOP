#ifndef WEAPON_H
#define WEAPON_H

#include "../config.hpp"
#include "player.hpp"
#include "movable_damage.hpp"
#include "../cells/game_field.hpp"

class Weapon final: public MovableDamage{
  public:
    Weapon(Player* player, GameField* field);
    ~Weapon();
    std::vector<Cell*> get_area();
    int get_damage() override;
  private:
    void center();
    int get_offset();
    bool can_move(Cell*) final;
  friend class WeaponController;
};

#endif //WEAPON_H