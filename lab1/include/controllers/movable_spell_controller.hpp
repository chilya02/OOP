#ifndef MOVABLE_SPELL_CONTROLLER_H
#define MOVABLE_SPELL_CONTROLLER_H

#include "movable_controller.hpp"
#include "../spells/movable_spell_interface.hpp"
#include "spell_controller_interface.hpp"


class MovableSpellController: public SpellControllerInterface, public MovableController{
  public:
    MovableSpellController(MovableSpellInterface*);
    ~MovableSpellController();
    bool handle_command(Command command) override;
  protected:
    MovableSpellInterface* spell;
};

#endif //# MOVABLE_SPELL_CONTROLLER_H