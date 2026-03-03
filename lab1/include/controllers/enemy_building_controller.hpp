#ifndef ENEMY_BUILDING_CONTROLLER_H
#define ENEMY_BUILDING_CONTROLLER_H

#include "../models/cell_objects/enemy.hpp"
#include "../models/cell_objects/enemy_building.hpp"

#include <vector>

class EnemyBuildingController{
  public:
    EnemyBuildingController(std::vector<Enemy*>* enemies, EnemyBuilding* building);
    void act();
  private:
    std::vector<Enemy*>* enemies;
    EnemyBuilding* building;
    int ticks;

    void create_enemy();
    
};
#endif // ENEMY_BUILDING_CONTROLLER_H