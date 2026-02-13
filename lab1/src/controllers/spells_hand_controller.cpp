#include "../../include/controllers/spells_hand_controller.hpp"
#include "../../include/models/cards/area_damage_card.hpp"
#include "../../include/models/cards/direct_damage_card.hpp"

SpellsHandController::SpellsHandController(SpellsHand* spells_hand, GameField* field, Player* player)
  :MenuController(*spells_hand), spells_hand(spells_hand), field(field), player(player){
    spells_hand->add_item(new AreaDamageCard(field, player), "Area damage");
    spells_hand->add_item(new DirectDamageCard(field, player), "Direct damage");
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
  if (command == Command::Ok){
    this->spells_hand->active = true;
    return true;
  }
  return MenuController::handle_command(command);
}

bool SpellsHandController::can_cast(){
  return this->spells_hand->get_cards().size() > 0;
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