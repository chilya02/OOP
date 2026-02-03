#ifndef SPELL_CARD_INTERFACE_H
#define SPELL_CARD_INTERFACE_H

#include "../../../controllers/interfaces/controller_interface.hpp"

class SpellCardInterface{
  public:
    virtual const char* text() = 0;
    virtual ControllerInterface* get_controller() = 0;
  protected:
    ControllerInterface* controller;
};

#endif //SPELL_CARD_INTERFACE_H