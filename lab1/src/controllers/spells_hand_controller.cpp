#include "../../include/controllers/spells_hand_controller.hpp"

SpellsHandController::SpellsHandController(SpellsHand* spells_hand):
  spells_hand(spells_hand), active(false){

  }

SpellsHandController::~SpellsHandController(){}

bool SpellsHandController::handle_command(Command command){
  if (this->is_active()){
    return this->get_active_controller()->handle_command(command);
  }
  switch (command)
  {
  case Command::Left:
    spells_hand->dec_index();
    return true;
    break;
  case Command::Right:
    spells_hand->inc_index();
    return true;
    break;
  case Command::Ok:
    this->active = true;
    return true;
  default:
    return false;
  }
}

bool SpellsHandController::can_cast(){
  return this->spells_hand->get_cards()->size() > 0;
}

bool SpellsHandController::is_active(){
  return this->active;
}

void SpellsHandController::deactivate(){
  this->active = false;
}

ControllerInterface* SpellsHandController::get_active_controller(){
  return this->spells_hand->get_selected_card()->get_controller();
}