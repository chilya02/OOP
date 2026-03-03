#ifndef MENU_INTERFACE_H
#define MENU_INTERFACE_H

class IMenu{
  public:
    virtual void inc_index() = 0;
    virtual void dec_index() = 0;
};

#endif