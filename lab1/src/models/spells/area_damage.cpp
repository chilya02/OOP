#include "../../../include/models/spells/area_damage.hpp"

AreaDamage::AreaDamage(GameField* field, Player* player, int damage, int range)
  :MovableDamage(player->get_cell(), damage), range(range), field(field){

}

AreaDamage::~AreaDamage(){}

std::vector<Cell*> AreaDamage::get_area(){
  std::vector<Cell*> res;
  Cell* anchor = this->get_cell();
  for (int y = anchor->get_y() - this->range + 1; y <= anchor->get_y(); y++){
    for (int x = anchor->get_x() - this->range + 1; x <= anchor->get_x(); x++){
      res.push_back(field->get_cell(y, x));
    }
  }
  return res;
}

bool AreaDamage::can_move(Cell* target){
  bool res = MovableCellObject::can_move(target);
  res = res && target->get_y() - this->range + 1 >= 0;
  res = res && target->get_x() - this->range + 1 >= 0;
  return res;
}