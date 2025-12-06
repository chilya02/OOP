#ifndef NCURSES_GAME_VIEW_H
#define NCURSES_GAME_VIEW_H

#include "../interfaces/view.hpp"
#include "../game.hpp"

#include "game_draw.hpp"
#include "progress_draw.hpp"

class NcursesViewController final:public ViewInterface{
  public:
    NcursesViewController(Game* game);
    ~NcursesViewController() final;
    void invalidate() override;
    void check_size() override;

  private:
    GameDraw* field_drawer;
    ProgressDraw* progress_drawer;
    bool is_visible;
    int col;
    int row;
    int field_x;
    int field_y;
    int min_width;
    int min_height;
    void draw();
    void print_size_message();
    void del_windows();
    void create_windows();
    bool calc_coordinates();
    void move_field();
};

#endif
