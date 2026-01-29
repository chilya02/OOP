#include "../../include/spells/area_damage_card.hpp"

AreaDamageCard::AreaDamageCard(GameField* field, Player* player){
  this->spell = new AreaDamage(field, player);
}

AreaDamageCard::~AreaDamageCard(){
  if (this->spell)
    delete this->spell;
}

const char* AreaDamageCard::text(){
  return " area ";
}
