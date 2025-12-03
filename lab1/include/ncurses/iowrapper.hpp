#ifndef NCURSES_IOWRAPPER_H
#define NCURSES_IOWRAPPER_H
#include "../abstract_iowrapper.hpp"
#include "../game.hpp"

class NcursesIOWrapper :public IOWrapper{
  public:
    NcursesIOWrapper(Game* game);
    virtual ~NcursesIOWrapper() final;
};
#endif // NCURSES_IOWRAPPER_H