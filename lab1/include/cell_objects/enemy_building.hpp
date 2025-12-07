#ifndef ENEMY_BUILD_H
#define ENEMY_BUILD_H

#include "physical_cell_obj.hpp"
#include "../config.hpp"

class EnemyBuilding: public PhysicalCellObject{
  public:
    EnemyBuilding(Cell* cell, int period = ENEMY_BUILDING_PERIOD);
  private:
    int tick_period; 
  friend class EnemyBuildingController;
};
#endif // ENEMY_BUILD_H
