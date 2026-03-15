#include "../../../include/models/weapon/weapon.hpp"

Weapon::Weapon(Player* player, GameField* field)
:direction(WeaponDirection::Top), player(player), field(field), mode(WeaponMode::Near){}

Weapon::~Weapon(){}

std::vector<Cell*> Weapon::get_area(){
  std::vector<Cell*> res;
  int y = player->get_cell()->get_y();
  int x = player->get_cell()->get_x();
  for (int count = 0; count < get_offset(); count++){
    switch (direction){
      case WeaponDirection::Top:
        y -= 1;
        break;
      case WeaponDirection::Bottom:
        y += 1;
        break;
      case WeaponDirection::Left:
        x -= 1;
        break;
      case WeaponDirection::Right:
        x += 1;
        break;
    }
    if (y >= 0 and y < field->get_height() and x >= 0 and x < field->get_width()){
      Cell* cell = field->get_cell(y, x);
      if (cell->is_impassable()){
        break;
      }
      res.push_back(cell);
    }
  }
  return res;
}

int Weapon::get_offset(){
  switch (this->mode){
  case WeaponMode::Near:
    return NEAR_FIGHT_RANGE;
  case WeaponMode::Far:
    return FAR_FIGHT_RANGE;
  default:
    return 0;
  }
}

int Weapon::get_damage(){
  switch (this->mode){
    case WeaponMode::Near:
      return NEAR_FIGHT_DAMAGE;
    break;
    case WeaponMode::Far:
      return FAR_FIGHT_DAMAGE;
    default:
      return FAR_FIGHT_DAMAGE;
  }
}

WeaponMode Weapon::get_mode(){
  return this->mode;
}