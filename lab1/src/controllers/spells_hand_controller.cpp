#include "../../include/controllers/spells_hand_controller.hpp"

SpellsHandController::SpellsHandController(SpellsHand* spells_hand):
  spells_hand(spells_hand){

  }

SpellsHandController::~SpellsHandController(){}

bool SpellsHandController::handle_command(Command command){
  switch (command)
  {
  case Command::Left:
    break;
  case Command::Right:
    break;
  case Command::Ok:
    break;
  default:
    return false;
  }
}