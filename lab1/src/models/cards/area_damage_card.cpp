#include "../../../include/models/cards/area_damage_card.hpp"
#include "../../../include/controllers/movable_damage_controller.hpp"

AreaDamageCard::AreaDamageCard(GameField* field, Player* player){
  this->spell = new AreaDamage(field, player);
  this->controller = new MovableDamageController(spell);
}

AreaDamageCard::~AreaDamageCard(){
  if (this->spell)
    delete this->spell;
}

const char* AreaDamageCard::text(){
  return " area ";
}
