#ifndef MENU_H
#define MENU_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
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
    std::string get_selected_name() override{
      if (this->items.empty())
        throw "Empty menu";
      return this->names[this->get_selected_item()];
    }
    
    std::vector <std::string> get_names() override{
      std::vector <std::string> res;
      for (T el: items){
        res.push_back(get_name(el));
      }
      return res;
    }

    std::string get_name(T item){
      if (this->names.contains(item)){
        return this->names[item];
      }
      throw "There is no name";
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
      this->active_index += this->items.size();
      this->active_index %= this->items.size();
    };
    int size() override{
      return this->items.size();
    };
    int get_selected_index() override{
      return this->active_index;
    };
  protected:
    int active_index;
    std::vector <T> items;
    std::map <T, std::string> names;
};

#endif // MENU_H
