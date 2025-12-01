#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"

class Player: public Entity{
  public:
    Player(int damage = 30, int HP = 100, int points = 0);
  private:
    int points;
};
#endif //PLAYER_H
