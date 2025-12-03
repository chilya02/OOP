#ifndef GAME_DRAW_H
#define GAME_DRAW_H

#include "../game.hpp"

#include <ncurses.h>
#include <vector>

#define DEFAULT_COLOR       0
#define CELL_COLOR          1
#define IMPASSABLE_COLOR    2
#define SLOW_COLOR          3
#define PLAYER_COLOR        4
#define AWAIT_COLOR         5
#define SLOWED_COLOR        6
#define BUILD_COLOR         7
#define ENEMY_COLOR         8

#define PLAYER_SYM          "/\\"
#define SLOW_SYM            "~~"
#define IMPASSABLE_SYM      "MM"
#define CELL_SYM            "  "
#define BUILD_SYM           "  "
#define ENEMY_SYM           "XX"

#define CELL_WIDTH          2
#define CELL_HEIGHT         1

class GameDraw{
  public:
    GameDraw(Game* game);
    ~GameDraw();
    void draw();
    int get_width();
    int get_height();
    void del_window();
    void create_window(int y, int x);
    void move(int x, int y);

  private:
    Game* game;

    WINDOW* win;
    
    int scr_height;
    int scr_width;
    
    void draw_area();
    void draw_player();
    void draw_enemies();
    void draw_building();
    void draw_cell(Cell*);
    void draw_area_cell(Cell*);
    void print(int, int, const char*, int);
};

#endif