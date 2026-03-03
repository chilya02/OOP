#include "../../../../include/models/cards/abstract/abstract_card.hpp"

AbstractCard::AbstractCard():damage(false), menu(false), movable(false) {}

bool AbstractCard::has_damage(){
  return this->damage;
}

bool AbstractCard::has_menu(){
  return this->menu;
}

bool AbstractCard::is_movable(){
  return this->movable;
}