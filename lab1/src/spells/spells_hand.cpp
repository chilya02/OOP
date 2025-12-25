#include "../../include/spells/spells_hand.hpp"
#include "../../include/spells/direct_damage_spell.hpp"

SpellsHand::SpellsHand(int size)
:size(size){
  this->cards = new std::vector <SpellCardInterface*>;
  this->cards->push_back(new DirectDamageSpell());
}

SpellsHand::~SpellsHand(){}

int SpellsHand::get_size(){
  return this->size;
}

std::vector <SpellCardInterface*>* SpellsHand::get_cards(){
  return this->cards;
}