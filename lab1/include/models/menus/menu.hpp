#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>

#include "interfaces/menu_interface.hpp"

template <typename T>
class Menu: public IMenu{
  public:
    Menu():active_index(0){};
    ~Menu(){};
    T get_selected_item(){
      if (this->items.empty())
        throw "Empty menu";
      return this->items[active_index];
    }
    std::string get_selected_name(){
      if (this->items.empty())
        throw "Empty menu";
      return this->names[this->get_selected_item()];
    }

    std::string get_name(T item){
      if (this->names.contains(item)){
        return this->names[item];
      }
    }

    void add_item(T item , std::string name){
      this->items.push_back(item);
      this->names[item] = name;
    }
    void inc_index() override{
      if (this->items.empty())
        return;
      this->active_index++;
      this->active_index %= this->items.size();
    };
    void dec_index() override{
      if (this->items.empty())
        return;
      this->active_index--;
      this->active_index %= this->items.size();
    };
  protected:
    int active_index;
    std::vector <T> items;
    std::map <T, std::string> names;
};

#endif // MENU_H