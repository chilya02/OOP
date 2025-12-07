#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"
#include "player_mode.hpp"

class Player final: public Entity{
  public:
    Player(Cell* cell, int damage = 30, int HP = 100, int points = 0);
    ~Player();
    PlayerMode get_mode();
  private:
    int points;
    PlayerMode mode;
  
  friend class PlayerController;
};
#endif //PLAYER_H
