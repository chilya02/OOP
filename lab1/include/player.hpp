#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"
#include "player_mode.hpp"

class Player: public Entity{
  public:
    Player(int damage = 30, int HP = 100, int points = 0);
    PlayerMode get_mode();
  private:
    int points;
    PlayerMode mode;
  
  friend class PlayerController;
};
#endif //PLAYER_H
