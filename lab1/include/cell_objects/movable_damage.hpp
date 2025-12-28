#ifndef MOVABLE_DAMAGE_H
#define MOVABLE_DAMAGE_H

#include "movable_cell_obj.hpp"
#include "../cells/game_field.hpp"
#include "player.hpp"

class MovableDamage:public MovableCellObject{
  public:
    MovableDamage(Cell*, GameField*, Player*);
    virtual int get_damage() = 0;
  protected:
    int damage;
    GameField* field;
    Player* player;

  friend class MovableDamageController;
};

#endif //MOVABLE_DAMAGE_H