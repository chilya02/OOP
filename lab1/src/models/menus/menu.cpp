#include "../../../include/models/menus/menu.hpp"
#include "../../../include/models/spells/spells_hand.hpp"

template <typename T>
Menu<T>::Menu(): active_index(0){};

template <typename T>
Menu<T>::~Menu(){};

template <typename T>
T Menu<T>::get_selected_item(){
  if (this->items.empty())
    throw "Empty menu";
  return this->items[active_index];
}

template <typename T>
std::string Menu<T>::get_selected_name(){
  if (this->items.empty())
    throw "Empty menu";
  return this->names[this->get_selected_item()];
}

template <typename T>
void Menu<T>::inc_index(){
  if (this->items.empty())
    return;
  this->active_index++;
  this->active_index %= this->items.size();
}

template <typename T>
void Menu<T>::dec_index(){
  if (this->items.empty())
    return;
  this->active_index--;
  this->active_index %= this->items.size();
}

template <typename T>
void Menu<T>::add_item(T item, std::string name){
  this->items.push_back(item);
  this->names[item] = name;
}

template class Menu<SpellCardInterface*>;