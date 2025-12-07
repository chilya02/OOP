#ifndef GAME_H
#define GAME_H

#include "../cell_objects/player.hpp"
#include "../cells/game_field.hpp"
#include "../cell_objects/enemy_building.hpp"
#include "../cell_objects/enemy.hpp"
#include "../cell_objects/weapon.hpp"

#include <vector>

class Game{
  public:
    Game(int height = 10, int width = 10, int period = 3);
    ~Game();
    static Game* create_random_game();
    static Game* create_user_game();
    GameField* field;
    Player* player;
    Weapon* weapon;
    EnemyBuilding* enemy_building;
    std::vector<Enemy*>* enemies;
};

#endif //GAME_H