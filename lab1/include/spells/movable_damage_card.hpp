#ifndef MOVABLE_DAMAGE_CARD_H
#define MOVABLE_DAMAGE_CARD_H

#include "spell_card_interface.hpp"
#include "../controllers/movable_damage_controller.hpp"
#include "../cell_objects/movable_damage.hpp"

class MovableDamageCard: public SpellCardInterface{
  public:
    MovableDamageController* get_controller() override;
  protected:
    MovableDamage* spell;
    MovableDamageController* controller;
};

#endif //MOVABLE_DAMAGE_CARD_H