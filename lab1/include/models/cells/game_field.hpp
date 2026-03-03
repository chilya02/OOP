#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "cell.hpp"

class GameField{
  public:
    GameField(int height, int width);
    int size();
    Cell* get_cell(int y, int x);
    int get_width();
    int get_height();
  private:
    int width;
    int height;
    Cell ***cells;
    void create_impassable_cells();
    void create_slow_cells();
    Cell** get_random_cell();
};
#endif // GAME_FIELD
