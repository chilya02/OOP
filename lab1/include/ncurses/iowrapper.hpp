#ifndef NCURSES_IOWRAPPER_H
#define NCURSES_IOWRAPPER_H
#include "../common/abstract_iowrapper.hpp"
#include "../common/game.hpp"

class NcursesIOWrapper final:public IOWrapper{
  public:
    NcursesIOWrapper(Game* game);
    virtual ~NcursesIOWrapper() final;
};
#endif // NCURSES_IOWRAPPER_H