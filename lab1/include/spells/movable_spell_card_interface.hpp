#ifndef MOVABLE_SPELL_CARD_INTERFACE_H
#define MOVABLE_SPELL_CARD_INTERFACE_H

#include "spell_card_interface.hpp"
#include "../cell_objects/movable_cell_obj.hpp"

class MovableSpellCardInterface:public SpellCardInterface, public MovableCellObject{
  
};

#endif //MOVABLE_SPELL_CARD_INTERFACE_H