#include "../../include/spells/movable_damage_spell.hpp"

MovableDamageSpell::MovableDamageSpell(GameField* field, Player* player, int damage)
: MovableDamage(player->get_cell(), field, player), damage(damage){

}
int MovableDamageSpell::get_damage(){
  return this->damage;
}