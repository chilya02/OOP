#ifndef ABS_GAME_DRAWER_H
#define ABS_GAME_DRAWER_H

#include "../../../models/game.hpp"
#include "abs_drawer.hpp"
#include <ncurses.h>

class AbstractGameDrawer: public AbstractDrawer{
  public:
    AbstractGameDrawer(Game* game);
    ~AbstractGameDrawer();
    void create_window(int y, int x);
    void del_window();
    //void move(int y, int x) override;

    int get_height();
    int get_width();
    
  protected:
    Game* game;
    int scr_height;
    int scr_width;
};
#endif // ABS_GAME_DRAWER_H