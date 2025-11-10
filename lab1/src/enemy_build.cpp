#include "enemy_build.hpp"

EnemyBuild::EnemyBuild(Cell* cell, int period):cell(cell), tick_period(period){

}

void EnemyBuild::tick(){
  this->tick_count += 1;
  
  if (this->tick_count > this->tick_period){
    this->create_enemy();
  }
}

void EnemyBuild::create_enemy(){
  
}
