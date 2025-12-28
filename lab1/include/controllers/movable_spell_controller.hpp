#ifndef MOVABLE_SPELL_CONTROLLER_H
#define MOVABLE_SPELL_CONTROLLER_H

#include "movable_controller.hpp"
#include "../spells/movable_damage.hpp"
#include "spell_controller_interface.hpp"


class MovableSpellController: public SpellControllerInterface, public MovableController{
  public:
    MovableSpellController(MovableDamage*);
    ~MovableSpellController();
    bool handle_command(Command command) override;
  protected:
    MovableDamage* spell;
};

#endif //# MOVABLE_SPELL_CONTROLLER_H