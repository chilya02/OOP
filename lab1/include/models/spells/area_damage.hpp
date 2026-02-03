#ifndef AREA_DAMAGE_H
#define AREA_DAMAGE_H

#include "abstract/movable_damage_spell.hpp"

class AreaDamage: public MovableDamageSpell{
  public:
    AreaDamage(GameField* ,Player*, int damage = 30);
    ~AreaDamage();
    std::vector<Cell*> get_area() override;
};

#endif //AREA_DAMAGE_H