#ifndef ENEMY_H
#define ENEMY_H

#include "entity.hpp"
#include "../config.hpp"

class Enemy final: public Entity{
  public:
    Enemy(Cell* cell, int damage = ENEMY_DAMAGE, int HP = 100);
    ~Enemy();

  friend class EnemiesController;
};
#endif // ENEMY_H
