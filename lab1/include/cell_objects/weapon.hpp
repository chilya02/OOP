#ifndef WEAPON_H
#define WEAPON_H

#include "../config.hpp"
#include "player.hpp"
#include "movable_cell_obj.hpp"
#include "../cells/game_field.hpp"

class Weapon final: public MovableCellObject{
  public:
    Weapon(Player* player, GameField* field);
    ~Weapon();
    std::vector<Cell*> get_area();
    int get_damage();
  private:
    Player* player;
    GameField* field;
    void center();
    int get_offset();
    bool can_move(Cell*) final;
  friend class WeaponController;
};

#endif //WEAPON_H