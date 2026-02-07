#ifndef AREA_DAMAGE_CARD_H
#define AREA_DAMAGE_CARD_H

#include "abstract/movable_damage_card.hpp"
#include "../spells/area_damage.hpp"

class AreaDamageCard : public MovableDamageCard{
  public:
    AreaDamageCard(GameField*, Player*);
    ~AreaDamageCard();
    const char* text() final;
};

#endif //AREA_DAMAGE_CARD_H