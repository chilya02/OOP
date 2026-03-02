#ifndef PLAYER_H
#define PLAYER_H

#include "abstract/entity.hpp"
#include "player_mode.hpp"

class Player final: public Entity{
  public:
    Player(Cell* cell, int damage = 30, int HP = 100, int points = 0, int coins = 0);
    ~Player();
    PlayerMode get_mode();
    int get_score();
    int get_coins();
  private:
    int points;
    int coins;
    void add_points(int);
    void add_coins(int);
    PlayerMode mode;
  
  friend class PlayerController;
};
#endif //PLAYER_H
