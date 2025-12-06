#ifndef ENTITY_H
#define ENTITY_H

#include "entity_status.hpp"
#include "movable_cell_obj.hpp"

class Entity:public MovableCellObject{ 
  public:
    Entity(Cell* cell, int damage = 30, int HP = 100); 

    bool is_alive();
    void hit(int damage);

    bool can_act();
    int get_HP();

    EntityStatus get_status();
    
    void change_status();

  protected:
    bool move(Cell* target) final;
    EntityStatus status;
    int damage;
    int HP; // Health points
};
#endif
