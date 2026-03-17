#ifndef NCURSES_IOWRAPPER_H
#define NCURSES_IOWRAPPER_H
#include "../abstract/abstract_iowrapper.hpp"
#include "../../models/app.hpp"

class NcursesIOWrapper final:public IOWrapper{
  public:
    NcursesIOWrapper(App* app);
    virtual ~NcursesIOWrapper() final;
};
#endif // NCURSES_IOWRAPPER_H