#include "../../../include/models/spells/area_damage.hpp"

AreaDamage::AreaDamage(GameField* field, Player* player, int damage)
  :MovableDamageSpell(field, player, damage){

}

AreaDamage::~AreaDamage(){}

std::vector<Cell*> AreaDamage::get_area(){
  std::vector<Cell*> res;
  return res;
}