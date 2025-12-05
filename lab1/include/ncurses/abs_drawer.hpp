#ifndef ABS_DRAWER_H
#define ABS_DRAWER_H

#include "../game.hpp"

#include <ncurses.h>

class AbstractDrawer{
  public:
    AbstractDrawer(Game* game);
    void create_window(int y, int x);
    void del_window();
    void move(int y, int x);
    
    virtual void draw() = 0;

    int get_height();
    int get_width();
    
  protected:
    Game* game;
    WINDOW* win;
    int scr_height;
    int scr_width;
};
#endif // ABS_DRAWER_H