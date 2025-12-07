#include "../../include/cell_objects/enemy.hpp"

Enemy::Enemy(Cell* cell, int damage, int HP):Entity(cell, damage, HP){
  this->status = EntityStatus::Stay;
};

Enemy::~Enemy(){}