#include "../../../include/models/cards/direct_damage_card.hpp"

DirectDamageCard::DirectDamageCard(GameField* field, Player* player){
  this->spell = new DirectDamage(field, player);
  this->controller = new MovableDamageController(spell);
}

DirectDamageCard::~DirectDamageCard(){}

const char* DirectDamageCard::text(){
  return "direct";
}