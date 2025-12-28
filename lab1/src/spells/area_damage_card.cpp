#include "../../include/spells/area_damage_card.hpp"

AreaDamageCard::AreaDamageCard(GameField* field, Player* player){
  this->spell = new AreaDamage(field, player);
}

AreaDamageCard::~AreaDamageCard(){}

const char* AreaDamageCard::text(){
  return "area";
}

// AreaDamageController* AreaDamageCard::get_controller(){
//   return this->controller;
// }