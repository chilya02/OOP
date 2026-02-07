#include "../../../../include/models/cell_objects/abstract/movable_damage.hpp"

MovableDamage::MovableDamage(Cell* cell, int damage)
  :MovableCellObject(cell), damage(damage){
  
}

bool MovableDamage::can_hit(){
  return true;
}

int MovableDamage::get_damage(){
  return this->damage;
}