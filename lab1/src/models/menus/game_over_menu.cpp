#include "../../../include/models/menus/game_over_menu.hpp"

GameOverMenu::GameOverMenu():Menu<GameOverMenuItems>(){
    this->add_item(GameOverMenuItems::NewGame, "New game");
    this->add_item(GameOverMenuItems::Exit, "Exit");
} 