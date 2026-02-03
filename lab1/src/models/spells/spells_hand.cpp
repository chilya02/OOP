#include "../../../include/models/spells/spells_hand.hpp"

SpellsHand::SpellsHand(int size)
:size(size){
  this->cards = new std::vector <SpellCardInterface*>;
}

SpellsHand::~SpellsHand(){
  if (this->cards){
    for (SpellCardInterface* card: *this->cards){
      delete card;
    }
    delete this->cards;
  }
}

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