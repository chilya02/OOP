#include "../../../../include/models/cards/abstract/movable_damage_card.hpp"

MovableDamageCard::MovableDamageCard():AbstractCard(){
  this->damage = true;
  this->movable = true;
}

MovableDamageController*  MovableDamageCard::get_controller(){
  return this->controller;
}

MovableDamage* MovableDamageCard::get_spell(){
  return this->spell;
}