#include "../../include/spells/spells_hand.hpp"
#include "../../include/spells/area_damage_card.hpp"

SpellsHand::SpellsHand(int size)
:size(size){
  this->cards = new std::vector <SpellCardInterface*>;
  this->cards->push_back(new AreaDamageCard());
  this->cards->push_back(new AreaDamageCard());
}

SpellsHand::~SpellsHand(){}

int SpellsHand::get_size(){
  return this->size;
}

std::vector <SpellCardInterface*>* SpellsHand::get_cards(){
  return this->cards;
}

SpellCardInterface* SpellsHand::get_selected_card(){
  return (*this->cards)[active_index];
}

void SpellsHand::inc_index(){
  this->active_index += 1;
  this->active_index %= this->cards->size();
}

void SpellsHand::dec_index(){
  this->active_index -= 1;
  this->active_index %= this->cards->size();
}