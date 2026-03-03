#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include "../interfaces/spell_card_interface.hpp"

class AbstractCard : public SpellCardInterface{
  public:
    AbstractCard();
    bool has_damage() override;
    bool has_menu() override;
    bool is_movable() override;
  protected:
    bool damage;
    bool menu;
    bool movable;
};

#endif //ABSTRACT_CARD_H