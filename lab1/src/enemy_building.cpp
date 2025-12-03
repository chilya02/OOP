#include "../include/enemy_building.hpp"

EnemyBuilding::EnemyBuilding(Cell* cell, int period):CellObject(cell), tick_period(period){

}

void EnemyBuilding::tick(){
  this->tick_count += 1;
  
  if (this->tick_count > this->tick_period){
    this->create_enemy();
  }
}

void EnemyBuilding::create_enemy(){
  
}
