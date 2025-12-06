#include "../../include/controllers/enemy_building_controller.hpp"

EnemyBuildingController::EnemyBuildingController(
  std::vector<Enemy*>* enemies, 
  EnemyBuilding* building)
:enemies(enemies), building(building), ticks(0){}

void EnemyBuildingController::act(){
  this->ticks += 1;
  if (this->ticks >= this->building->tick_period){
    this->create_enemy();
    this->ticks -= this->building->tick_period;
  }
}

void EnemyBuildingController::create_enemy(){
  std::vector<Cell*> neighbors = this->building->get_cell()->get_free_neighbors();
  int cell_num = rand() % neighbors.size();
  Enemy* enemy = new Enemy(neighbors[cell_num]);
  this->enemies->push_back(enemy);
}