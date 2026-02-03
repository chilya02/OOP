#include "../../../../include/models/cell_objects/abstract/movable_damage.hpp"

MovableDamage::MovableDamage(Cell* cell, GameField* field, Player* player)
  :MovableCellObject(cell), field(field), player(player){
  
}