#ifndef DIRECT_DAMAGE_H
#define DIRECT_DAMAGE_H

#include "abstract/movable_damage_spell.hpp"

class DirectDamage: public MovableDamageSpell{
  public:
    DirectDamage(GameField*, Player*, int damage = 40);
    ~DirectDamage();
    std::vector<Cell*> get_area() override;
};

#endif // DIRECT_DAMAGE_H