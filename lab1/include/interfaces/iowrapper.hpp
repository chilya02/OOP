#ifndef IOWRAPPER_INTERFACE_H
#define IOWRAPPER_INTERFACE_H

#include "command.hpp"
#include "view.hpp"

class IOWrapperInterface{
  public:
    virtual CommandInterface* get_command() = 0;
    virtual ViewInterface* get_view() = 0;
};

#endif // IOWRAPPER_H