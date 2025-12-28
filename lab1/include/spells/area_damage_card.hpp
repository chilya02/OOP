#ifndef AREA_DAMAGE_CARD_H
#define AREA_DAMAGE_CARD_H

#include "movable_damage_card.hpp"
#include "area_damage.hpp"

class AreaDamageCard : public MovableDamageCard{
  public:
    AreaDamageCard(GameField*, Player*);
    ~AreaDamageCard();
    const char* text() final;
  private:
    AreaDamage* spell;
};

#endif //AREA_DAMAGE_CARD_H