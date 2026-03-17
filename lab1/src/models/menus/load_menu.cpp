#include "../../../include/models/menus/load_menu.hpp"

LoadMenu::LoadMenu():Menu<LoadMenuItems>(){
    this->add_item(LoadMenuItems::NewGame, "New game");
    this->add_item(LoadMenuItems::Load, "Load");
    this->add_item(LoadMenuItems::Exit, "Exit");
} 