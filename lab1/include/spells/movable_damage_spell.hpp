#ifndef MOVABLE_DAMAGE_SPELL_H
#define MOVABLE_DAMAGE_SPELL_H

#include "../cell_objects/movable_damage.hpp"

class MovableDamageSpell:public MovableDamage{
  public:
    MovableDamageSpell(GameField*, Player*, int);
    ~MovableDamageSpell();
    int get_damage() override;
  protected:
    int damage;
};

#endif //MOVABLE_DAMAGE_SPELL_H