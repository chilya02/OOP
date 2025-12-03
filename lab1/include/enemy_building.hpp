#ifndef ENEMY_BUILD_H
#define ENEMY_BUILD_H
#include "cell.hpp"
#include "cell_obj.hpp"

class EnemyBuilding: public CellObject{
  public:
    EnemyBuilding(Cell* cell, int period);
    ~EnemyBuilding();
    void tick();
  private:
    int tick_period; 
    int tick_count = 0;
    void create_enemy();
};
#endif // ENEMY_BUILD_H
