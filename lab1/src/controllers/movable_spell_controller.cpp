#include "../../include/controllers/movable_spell_controller.hpp"

MovableSpellController::MovableSpellController(MovableSpell* spell)
: MovableController(spell){}

MovableSpellController::~MovableSpellController(){}

bool MovableSpellController::handle_command(Command command){
  return this->move_obj(command);
}

