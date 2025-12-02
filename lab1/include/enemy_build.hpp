#ifndef ENEMY_BUILD_H
#define ENEMY_BUILD_H
#include "cell.hpp"
#include "cell_obj.hpp"

class EnemyBuild: public CellObject{
  public:
    EnemyBuild(Cell* cell, int period);
    ~EnemyBuild();
    void tick();
  private:
    int tick_period; 
    int tick_count = 0;
    void create_enemy();
};
#endif // ENEMY_BUILD_H
