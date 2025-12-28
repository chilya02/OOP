#include "../../include/controllers/movable_damage_controller.hpp"

MovableDamageController::MovableDamageController(MovableDamage* damage)
: MovableController(damage), damage(damage){}

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

int MovableDamageController::get_damage(){
  return this->damage->get_damage();
}