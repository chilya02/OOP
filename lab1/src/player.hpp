#ifndef PLAYER_H
#define PLAYER_H

#include "entity.hpp"

class Player: public Entity{
  public:
    Player(int damage = 30, int HP = 100, int points = 0);
    bool is_alive();
    bool hit(int damage);
  private:
    int points;

  friend class GameView;
};
#endif //PLAYER_H
