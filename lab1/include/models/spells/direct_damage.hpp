#ifndef DIRECT_DAMAGE_H
#define DIRECT_DAMAGE_H

#include "../cell_objects/abstract/movable_damage.hpp"

class DirectDamage: public MovableDamage{
  public:
    DirectDamage(GameField*, Player*, int damage = 40);
    ~DirectDamage();
    std::vector<Cell*> get_area() override;
    bool can_hit() override;
  private:
    Player* player;
};

#endif // DIRECT_DAMAGE_H