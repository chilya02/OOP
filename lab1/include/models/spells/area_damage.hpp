#ifndef AREA_DAMAGE_H
#define AREA_DAMAGE_H

#include "../cell_objects/abstract/movable_damage.hpp"

class AreaDamage: public MovableDamage{
  public:
    AreaDamage(GameField* ,Player*, int damage = 30, int range = 2);
    ~AreaDamage();
    std::vector<Cell*> get_area() override;
    bool can_move(Cell*) override;
  private:
    int range;
    GameField* field;
};

#endif //AREA_DAMAGE_H