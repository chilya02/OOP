#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "game_field.hpp"

#include "player.hpp"

#include <ncurses.h>
#include <vector>

#define DEFAULT_COLOR       0
#define CELL_COLOR          1
#define IMPASSABLE_COLOR    2
#define SLOW_COLOR          3
#define PLAYER_COLOR        4
#define AWAIT_COLOR         5
#define SLOWED_COLOR        6

#define PLAYER_SYM          "/\\"
#define SLOW_SYM            "~~"
#define IMPASSABLE_SYM      "MM"
#define CELL_SYM            "  "

#define CELL_WIDTH          2
#define CELL_HEIGHT         1

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
    int field_scr_width;
    int field_scr_height;
    void draw();
    void draw_area();
    std::vector<Cell*> get_move_area();
    void draw_cell(int, int, Cell*);
    void draw_area_cell(Cell*);
    void draw_player(int, int);
    void print(int, int, const char*, int);
    void del_windows();
    void create_windows();
    bool calc_coordinates();
    void move_field();
    WINDOW* field_window;
    WINDOW* q_menu_window;
};

#endif
