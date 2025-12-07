#include "../../include/cell_objects/weapon.hpp"

Weapon::Weapon(Player* player, GameField* field)
:MovableCellObject(player->get_cell()), player(player), field(field){}

std::vector<Cell*> Weapon::get_area(){
  std::vector<Cell*> res;
  int mid_y = this->player->get_cell()->get_y();
  int mid_x = this->player->get_cell()->get_x();
  int offset = this->get_offset();
  for (int y = mid_y - offset; y < mid_y + offset + 1; y++){
      for (int x = mid_x - offset; x < mid_x + offset + 1; x++){
        Cell* target = this->field->get_cell(y, x);
        if (this->can_move(target)){
          res.push_back(target);
        }
      }
    }
  return res;
}

int Weapon::get_offset(){
  switch (this->player->get_mode()){
  case PlayerMode::NearFight:
    return NEAR_FIGHT_RANGE;
  case PlayerMode::FarFight:
    return FAR_FIGHT_RANGE;
  default:
    return 0;
  }
}

bool Weapon::can_move(Cell* target){
  bool flag = MovableCellObject::can_move(target);
  flag = flag && target != this->player->get_cell();
  flag = flag && abs(target->get_y() - player->get_cell()->get_y()) <= get_offset();
  flag = flag && abs(target->get_x() - player->get_cell()->get_x()) <= get_offset();
  return flag;
}

void Weapon::center(){
  this->cell = this->player->get_cell();
}

int Weapon::get_damage(){
  switch (this->player->get_mode()){
    case PlayerMode::NearFight:
      return 40;
    break;
    case PlayerMode::FarFight:
      return 20;
    default:
      return 20;
  }
}