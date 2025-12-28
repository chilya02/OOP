#ifndef SPELL_CARD_INTERFACE_H
#define SPELL_CARD_INTERFACE_H

#include "../controllers/spell_controller_interface.hpp"

class SpellCardInterface{
  public:
    virtual const char* text() = 0;
    virtual SpellControllerInterface* get_controller() = 0;
  protected:
    SpellControllerInterface* controller;
};

#endif //SPELL_CARD_INTERFACE_H