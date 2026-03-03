#include "../../../include/models/spells/direct_damage.hpp"

DirectDamage::DirectDamage(GameField* field, Player* player, int damage)
  :MovableDamage(player->get_cell(), damage), player(player){

}

DirectDamage::~DirectDamage(){}

std::vector<Cell*> DirectDamage::get_area(){
  std::vector<Cell*> res;
  res.push_back(this->get_cell());
  return res;
}

bool DirectDamage::can_hit(){
  Cell* cell = this->get_cell();
  return cell->is_busy() && cell != player->get_cell();
}