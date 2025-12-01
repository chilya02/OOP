#include "entity.hpp"

Entity::Entity(int damage, int HP):damage(damage), HP(HP){};

bool Entity::is_alive(){
  return this->HP > 0;
}

bool Entity::move(Cell* target){
  if (!target || target->is_impassable())
    return false;
  this->cell = target;
  this->status = target->is_slow() ? EntityStatus::Slowed : EntityStatus::Stay;
  return true;
}

bool Entity::move_down(){
  Cell* bottom = this->cell->get_bottom();
  return  this->move(bottom);
}

bool Entity::move_up(){
  Cell* top = this->cell->get_top();
  return this->move(top);
}

bool Entity::move_left(){
  Cell* left = this->cell->get_left();
  return this->move(left);
}

bool Entity::move_right(){
  Cell* right = this->cell->get_right();
  return this->move(right);
}

void Entity::change_status(){
  switch (this->status)
  {
  case EntityStatus::Await:
    break;
  case EntityStatus::Slowed:
    this->status = EntityStatus::Stay;
    break;
  case EntityStatus::Stay:
    this->status = EntityStatus::Await;
    break;
  }
}

bool Entity::can_act(){
  return this->status == EntityStatus::Await;
}

Cell* Entity::get_cell(){
  return this->cell;
}

EntityStatus Entity::get_status(){
  return this->status;
}
