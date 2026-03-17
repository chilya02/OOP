#ifndef LOAD_MENU_H
#define LOAD_MENU_H
#include "menu.hpp"

enum class LoadMenuItems{
    NewGame,
    Load,
    Exit
};

class LoadMenu: public Menu<LoadMenuItems>{
    public:
        LoadMenu();
    
};

#endif //LOAD_MENU_H