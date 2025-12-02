#include "../include/enemy.hpp"

Enemy::Enemy(Cell* cell):Entity(cell){
  this->status = EntityStatus::Stay;
};
