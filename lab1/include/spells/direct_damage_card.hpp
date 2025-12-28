#ifndef DIRECT_DAMAGE_SPELL_H
#define DIRECT_DAMAGE_SPELL_H

#include "movable_damage_card.hpp"

class DirectDamageCard : public MovableDamageCard{
  public:
    DirectDamageCard();
    ~DirectDamageCard();
    const char* text() final;
};

#endif //DIRECT_DAMAGE_SPELL_H