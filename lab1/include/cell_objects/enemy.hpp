#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class Enemy: public Entity{
  public:
    Enemy(Cell* cell);
    ~Enemy();
  private:
    //bool move(Cell* target) final;

  friend class EnemiesController;
};
#endif // ENEMY_H
