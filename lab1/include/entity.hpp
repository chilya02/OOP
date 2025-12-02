#ifndef ENTITY_H
#define ENTITY_H

#include "cell.hpp"
#include "entity_status.hpp"
#include "cell_obj.hpp"

class Entity:public CellObject{ 
  public:
    Entity(Cell* cell, int damage = 30, int HP = 100); 

    bool is_alive();
    bool hit(int damage);

    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();

    bool can_act();

    EntityStatus get_status();
    
    void change_status();

  protected:
    Entity(Cell* cell);
    bool move(Cell* target);
    EntityStatus status = EntityStatus::Await;
    int damage;
    int HP; // Health points
};
#endif
