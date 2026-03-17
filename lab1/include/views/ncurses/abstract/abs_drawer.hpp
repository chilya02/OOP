#ifndef ABS_DRAWER_H
#define ABS_DRAWER_H

#include <ncurses.h>

class AbstractDrawer{
  public:
    AbstractDrawer();
    virtual void draw() = 0;
    void move(int y, int x);

  protected:
    WINDOW* win;
};

#endif //ABS_DRAWER_H