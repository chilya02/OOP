#ifndef SPELLS_HAND_H
#define SPELLS_HAND_H

#include "spell_card_interface.hpp"
#include "vector"

class SpellsHand{
  public:
    SpellsHand(int size = 4);
    ~SpellsHand();
    int get_size();
    std::vector <SpellCardInterface*>* get_cards();
  private:
    std::vector <SpellCardInterface*>* cards;
    int size;
    int active_index = 0;
};

#endif // SPELLS_HAND_H