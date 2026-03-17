#ifndef GAME_OVER_MENU_H
#define GAME_OVER_MENU_H

#include "menu.hpp"

enum class GameOverMenuItems{
  NewGame,
  Exit,
};

class GameOverMenu: public Menu <GameOverMenuItems>{
  public:
    GameOverMenu();
};

#endif //GAME_OVER_MENU_H