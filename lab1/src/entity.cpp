#include "../include/entity.hpp"

Entity::Entity(Cell* cell, int damage, int HP):MovableCellObject(cell), damage(damage), HP(HP){};

bool Entity::is_alive(){
  return this->HP > 0;
}

bool Entity::move(Cell* target){
  bool res = MovableCellObject::move(target);
  this->status = target->is_slow() ? EntityStatus::Slowed : EntityStatus::Stay;
  return res;
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

EntityStatus Entity::get_status(){
  return this->status;
}
