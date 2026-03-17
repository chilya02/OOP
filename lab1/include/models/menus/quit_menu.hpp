#ifndef QUIT_MENU_H
#define QUIT_MENU_H

#include "menu.hpp"

enum class QuitMenuItems{
  Continue,
  Save,
  Exit
};

class QuitMenu: public Menu<QuitMenuItems>{
  public:
    QuitMenu();
};

#endif //QUIT_MENU_H