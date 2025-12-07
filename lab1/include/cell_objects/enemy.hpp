#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"

class Enemy final: public Entity{
  public:
    Enemy(Cell* cell);
    ~Enemy();

  friend class EnemiesController;
};
#endif // ENEMY_H
