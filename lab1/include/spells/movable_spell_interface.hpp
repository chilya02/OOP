#ifndef MOVABLE_SPELL_CARD_INTERFACE_H
#define MOVABLE_SPELL_CARD_INTERFACE_H

#include "../cell_objects/movable_cell_obj.hpp"

class MovableSpellInterface:public MovableCellObject{
  public:
    MovableSpellInterface(Cell* cell);
};

#endif //MOVABLE_SPELL_CARD_INTERFACE_H