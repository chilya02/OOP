#include "../../include/spells/area_damage.hpp"

AreaDamage::AreaDamage(GameField* field, Player* player, int damage)
  :MovableDamageSpell(field, player, damage){

}
AreaDamage::~AreaDamage(){}