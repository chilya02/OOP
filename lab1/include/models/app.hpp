#ifndef APP_H
#define APP_H

#include "game.hpp"
#include "app_state.hpp"
#include "menus/load_menu.hpp"
#include "menus/quit_menu.hpp"
#include "menus/game_over_menu.hpp"
#include "../common/loader.hpp"
#include "../common/serializer.hpp"

class App{
    public:
        App();
        ~App();
        AppState get_state();
        Game* get_game();
        LoadMenu* get_load_menu();
        QuitMenu* get_quit_menu();
        GameOverMenu* get_game_over_menu();
    private:
        Loader* loader;
        Serializer* serializer;
        Game* game;
        AppState state;
        GameOverMenu* game_over_menu;
        LoadMenu* load_menu;
        QuitMenu* quit_menu;
    friend class AppController;
};

#endif