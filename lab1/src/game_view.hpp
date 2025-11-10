#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "game_field.hpp"
#include "player.hpp"

class GameView{
  public:
    GameView(GameField* field, Player* player);
    void invalidate();
    void check_size();

  private:
    GameField* field;
    Player* player;
    int col = 0;
    int row = 0;
    int x_start = 0;
    int y_start = 0;
    void draw();
    void draw_cell(int x, int y, Cell* cell);
    void draw_player(int x, int y);
    bool calc_coordinates();
};

#endif
