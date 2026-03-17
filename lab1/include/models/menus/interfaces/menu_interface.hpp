#ifndef MENU_INTERFACE_H
#define MENU_INTERFACE_H

#include <string>
#include <vector>

class IMenu{
  public:
    virtual void inc_index() = 0;
    virtual void dec_index() = 0;
    virtual int size() = 0;
    virtual int get_selected_index() = 0;
    virtual std::string get_selected_name() = 0;
    virtual std::vector <std::string> get_names() = 0;
};

#endif