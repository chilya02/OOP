#include "../../include/controllers/spells_hand_controller.hpp"
#include "../../include/models/cards/area_damage_card.hpp"
#include "../../include/models/cards/direct_damage_card.hpp"

SpellsHandController::SpellsHandController(SpellsHand* spells_hand, GameField* field, Player* player):
  spells_hand(spells_hand), field(field), player(player){
    spells_hand->cards->push_back(new AreaDamageCard(field, player));
    spells_hand->cards->push_back(new DirectDamageCard(field, player));
  }

SpellsHandController::~SpellsHandController(){}

bool SpellsHandController::handle_command(Command command){
  if (this->is_active()){
    if (command == Command::Escape){
      this->deactivate();
      return true;
    }
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
    this->spells_hand->active = true;
    return true;
  default:
    return false;
  }
}

bool SpellsHandController::can_cast(){
  return this->spells_hand->get_cards()->size() > 0;
}

bool SpellsHandController::is_active(){
  return this->spells_hand->is_active();
}

void SpellsHandController::deactivate(){
  this->spells_hand->active = false;
}

void SpellsHandController::remove_selected_card(){
  this->spells_hand->remove_selected_card();
}

ControllerInterface* SpellsHandController::get_active_controller(){
  return this->spells_hand->get_selected_card()->get_controller();
}

SpellCardInterface* SpellsHandController::get_active_card(){
  return this->spells_hand->get_selected_card();
}