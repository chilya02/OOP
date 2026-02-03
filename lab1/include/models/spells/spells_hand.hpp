#ifndef SPELLS_HAND_H
#define SPELLS_HAND_H

#include "../cards/interfaces/spell_card_interface.hpp"
#include "vector"

class SpellsHand{
  public:
    SpellsHand(int size = 4);
    ~SpellsHand();
    int get_size();
    SpellCardInterface* get_selected_card();
    std::vector <SpellCardInterface*>* get_cards();
  private:
    std::vector <SpellCardInterface*>* cards;
    int size;
    int active_index = 0;
    void inc_index();
    void dec_index();

    friend class SpellsHandController;
};

#endif // SPELLS_HAND_H