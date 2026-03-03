#include "../../../include/models/spells/spells_hand.hpp"

SpellsHand::SpellsHand(int size)
  :Menu<SpellCardInterface*>(), active(false), size(size){
}

SpellsHand::~SpellsHand(){

}

int SpellsHand::get_size(){
  return this->size;
}

std::vector <SpellCardInterface*>& SpellsHand::get_cards(){
  return this->items;
}

SpellCardInterface* SpellsHand::get_selected_card(){
  return this->get_selected_item();
}

bool SpellsHand::is_active(){
  return this->active;
}

void SpellsHand::remove_selected_card(){
  this->items.erase(items.begin() + this->active_index);
  this->active_index %= this->items.size();
}