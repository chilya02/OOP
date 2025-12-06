#include "../../include/cell_objects/enemy.hpp"

Enemy::Enemy(Cell* cell):Entity(cell){
  this->status = EntityStatus::Stay;
};
