#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "game_field.hpp"
#include "enemy_building.hpp"
#include "enemy.hpp"

#include <vector>

class Game{
  public:
    Game(int height = 10, int width = 10, int period = 3);
    ~Game();
    static Game* create_random_game();
    static Game* create_user_game();
    GameField* field;
    Player* player;
    EnemyBuilding* enemy_building;
    std::vector<Enemy*>* enemies;
};

#endif //GAME_H