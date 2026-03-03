#include "../../../include/models/cell_objects/enemy_building.hpp"

EnemyBuilding::EnemyBuilding(Cell* cell, int period):PhysicalCellObject(cell), tick_period(period){}