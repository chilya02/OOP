#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "game_field.hpp"

#include "enemy_build.hpp"
#include "player.hpp"
#include "game_draw.hpp"

#include <ncurses.h>
#include <vector>


class ViewController{
  public:
    ViewController(GameField* field, Player* player, EnemyBuild* build, std::vector<Enemy*>* enemies);
    ~ViewController();
    void invalidate();
    void check_size();

  private:
    GameDraw* field_drawer;
    bool is_visible;
    int col;
    int row;
    int field_x;
    int field_y;
    void draw();
    void del_windows();
    void create_windows();
    bool calc_coordinates();
    void move_field();
};

#endif
