#ifndef MOVABLE_SPELL_INTERFACE_H
#define MOVABLE_SPELL_INTERFACE_H

#include "../cell_objects/movable_cell_obj.hpp"

class MovableSpell:public MovableCellObject{
  public:
    MovableSpell(Cell* cell);
};

#endif //MOVABLE_SPELL_INTERFACE_H