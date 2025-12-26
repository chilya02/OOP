#ifndef AREA_DAMAGE_CONTROLLER_H
#define AREA_DAMAGE_CONTROLLER_H

#include "movable_spell_controller.hpp"
#include "../spells/area_damage.hpp"

class AreaDamageController: public MovableSpellController{
  public:
    AreaDamageController(AreaDamage* );
    ~AreaDamageController();
};

#endif // AREA_DAMAGE_CONTROLLER_H