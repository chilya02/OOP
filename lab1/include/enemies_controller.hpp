#ifndef ENEMIES_CONTROLLER_H
#define ENEMIES_CONTROLLER_H

#include "enemy.hpp"
#include "game_field.hpp"
#include "player.hpp"
#include "cell.hpp"

#include <map>
#include <vector>

class EnemiesController{
  public:
    EnemiesController(std::vector<Enemy*>* enemies, Player* player, GameField* field);
    void act();
  private:
    std::vector<Enemy*>* enemies;
    Player* player;
    GameField* field;
    void move_enemy(Enemy* enemy);
    Cell* get_optimal_cell(Enemy* enemy);
    float distance(Cell*);
    std::map<Cell*, int>  BFS();
};

#endif //ENEMIES_CONTROLLER_H