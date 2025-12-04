#ifndef ABS_DRAWER_H
#define ABS_DRAWER_H

#include <ncurses.h>

class AbstractDrawer{
  public:
    AbstractDrawer();
    virtual void create_window(int y, int x) = 0;
    void del_window();
  protected:
    WINDOW* win;
};
#endif // ABS_DRAWER_H