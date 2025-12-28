#include "../../include/cell_objects/movable_damage.hpp"

MovableDamage::MovableDamage(Cell* cell, GameField* field, Player* player)
  :MovableCellObject(cell), field(field), player(player){
  
}