#ifndef MOVABLE_DAMAGE_H
#define MOVABLE_DAMAGE_H

#include "../cell_objects/movable_cell_obj.hpp"

class MovableDamage:public MovableCellObject{
  public:
    MovableDamage(Cell* cell);
};

#endif //MOVABLE_DAMAGE_H