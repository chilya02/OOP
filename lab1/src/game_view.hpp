#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "game_field.hpp"
#include "player.hpp"

#include <ncurses.h>

class GameView{
  public:
    GameView(GameField* field, Player* player);
    ~GameView();
    void invalidate();
    void check_size();

  private:
    GameField* field;
    Player* player;
    bool is_visible;
    int col;
    int row;
    int x_start;
    int y_start;
    int scr_width;
    int scr_height;
    void draw();
    void draw_cell(int x, int y, Cell* cell);
    void draw_player(int x, int y);
    void del_windows();
    void create_windows();
    bool calc_coordinates();
    void move_field();
    WINDOW* field_window;
    WINDOW* q_menu_window;
};

#endif
