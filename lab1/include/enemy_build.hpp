#ifndef ENEMY_BUILD_H
#define ENEMY_BUILD_H
#include "cell.hpp"

class EnemyBuild{
  public:
    EnemyBuild(Cell* cell, int period);
    ~EnemyBuild();
    void tick();
    Cell* get_cell();
  private:
    Cell* cell;
    int tick_period; 
    int tick_count = 0;
    void create_enemy();
};
#endif // ENEMY_BUILD_H
