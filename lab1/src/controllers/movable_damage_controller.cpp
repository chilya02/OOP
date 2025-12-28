#include "../../include/controllers/movable_damage_controller.hpp"

MovableDamageController::MovableDamageController(MovableDamage* spell)
: MovableController(spell){}

MovableDamageController::~MovableDamageController(){}

bool MovableDamageController::handle_command(Command command){
  if (this->move_obj(command)){
    return true;
  }
  if (command == Command::Ok){
    if (damage->get_cell() == damage->player->get_cell())
      return false;
    return true;
  }
  return false;
}