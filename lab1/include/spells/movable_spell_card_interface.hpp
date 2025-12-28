#ifndef MOVABLE_SPELL_CARD_H
#define MOVABLE_SPELL_CARD_H

#include "spell_card_interface.hpp"
#include "../controllers/movable_spell_controller.hpp"
#include "movable_damage.hpp"

class MovableSpellCardInterface:public SpellCardInterface{
  public:
    MovableSpellController* get_controller() override = 0;
  protected:
    MovableDamage* spell;
    MovableSpellController* conrtoller;
};

#endif //MOVABLE_SPELL_CARD_H