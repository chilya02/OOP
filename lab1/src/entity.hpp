#ifndef ENTITY_H
#define ENTITY_H

#include "cell.hpp"
#include "entity_status.hpp"

class Entity{ 
  public:
    Entity(int damage = 30, int HP = 100); 

    bool is_alive();
    bool hit(int damage);

    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();

  protected:
    bool move(Cell* target);
    EntityStatus status = EntityStatus::Await;
    int damage;
    int HP; // Health points
    Cell* cell;
    virtual std::string view();

  friend class GameProcess;
  friend class GameView;
};
#endif
