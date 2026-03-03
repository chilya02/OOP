#ifndef DIRECT_DAMAGE_SPELL_H
#define DIRECT_DAMAGE_SPELL_H

#include "abstract/movable_damage_card.hpp"
#include "../spells/direct_damage.hpp"

class DirectDamageCard : public MovableDamageCard{
  public:
    DirectDamageCard(GameField*, Player*);
    ~DirectDamageCard();
    const char* text() final;
};

#endif //DIRECT_DAMAGE_SPELL_H