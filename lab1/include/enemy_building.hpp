#ifndef ENEMY_BUILD_H
#define ENEMY_BUILD_H
#include "cell.hpp"
#include "cell_obj.hpp"

class EnemyBuilding: public CellObject{
  public:
    EnemyBuilding(Cell* cell, int period);
  private:
    int tick_period; 
  friend class EnemyBuildingController;
};
#endif // ENEMY_BUILD_H
