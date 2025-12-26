#ifndef DIRECT_DAMAGE_CONTROLLER_H
#define DIRECT_DAMAGE_CONTROLLER_H

#include "movable_spell_controller.hpp"
#include "../spells/direct_damage.hpp"

class DirectDamageController: public MovableSpellController{
  public:
    DirectDamageController(DirectDamage*);
    ~DirectDamageController();
};

#endif // DIRECT_DAMAGE_CONTROLLER_H