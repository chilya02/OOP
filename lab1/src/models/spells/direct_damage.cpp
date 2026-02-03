#include "../../../include/models/spells/direct_damage.hpp"

DirectDamage::DirectDamage(GameField* field, Player* player, int damage)
  :MovableDamageSpell(field, player, damage){

}

DirectDamage::~DirectDamage(){}

std::vector<Cell*> DirectDamage::get_area(){
  std::vector<Cell*> res;
  return res;
}