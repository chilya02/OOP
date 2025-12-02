#ifndef ENEMIES_CONTROLLER_H
#define ENEMIES_CONTROLLER_H

#include "enemy.hpp"
#include "game_field.hpp"
#include "player.hpp"

#include <vector>

class EnemiesController{
  public:
    EnemiesController(std::vector<Enemy*>* enemies, Player* player, GameField* field);
    void act();
  private:
    std::vector<Enemy*>* enemies;
    Player* player;
    GameField* field;
    void dijkstra(Enemy* enemy);
};

#endif //ENEMIES_CONTROLLER_H