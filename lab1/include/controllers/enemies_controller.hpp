#ifndef ENEMIES_CONTROLLER_H
#define ENEMIES_CONTROLLER_H

#include "../models/cell_objects/enemy.hpp"
#include "../models/cell_objects/player.hpp"
#include "../models/weapon/weapon.hpp"
#include "../models/cells/game_field.hpp"

#include <map>
#include <vector>

class EnemiesController{
  public:
    EnemiesController(std::vector<Enemy*>* enemies, Player* player, GameField* field);
    void act();
    int hit(std::vector<Cell*>, int);
    int hit(Cell*, int);
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