#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "cell.hpp"

class GameField{
  public:
    GameField(int height, int width, int period);
    int size();
  private:
    int width;
    int height;
    Cell ***cells;
    void create_impassable_cells();
    void create_slow_cells();
    void create_enemy_build(int period);
    Cell** get_random_cell();
  friend class GameView;
  friend class GameProcess;
};
#endif // GAME_FIELD
