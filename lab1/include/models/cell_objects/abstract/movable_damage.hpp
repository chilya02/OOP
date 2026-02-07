#ifndef MOVABLE_DAMAGE_H
#define MOVABLE_DAMAGE_H

#include "movable_cell_obj.hpp"
#include "../../cells/game_field.hpp"
#include "../player.hpp"

class MovableDamage:public MovableCellObject{
  public:
    MovableDamage(Cell*, int);
    int get_damage();
    virtual bool can_hit();
    virtual std::vector <Cell*> get_area() = 0;
  protected:
    int damage;
  friend class MovableDamageController;
};

#endif //MOVABLE_DAMAGE_H