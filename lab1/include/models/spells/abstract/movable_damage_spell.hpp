#ifndef MOVABLE_DAMAGE_SPELL_H
#define MOVABLE_DAMAGE_SPELL_H

#include "../../cell_objects/abstract/movable_damage.hpp"

class MovableDamageSpell:public MovableDamage{
  public:
    MovableDamageSpell(GameField*, Player*, int);
    virtual ~MovableDamageSpell();
    int get_damage() override;
    virtual std::vector <Cell*> get_area() = 0; 
  protected:
    int damage;
};

#endif //MOVABLE_DAMAGE_SPELL_H