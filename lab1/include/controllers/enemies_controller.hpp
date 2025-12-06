#ifndef ENEMIES_CONTROLLER_H
#define ENEMIES_CONTROLLER_H

#include "../cell_objects/enemy.hpp"
#include "../cell_objects/player.hpp"
#include "../cells/game_field.hpp"

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
    bool can_hit(Enemy* enemy);
    std::map<Cell*, int>  BFS();
};

#endif //ENEMIES_CONTROLLER_H