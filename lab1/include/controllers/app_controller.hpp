#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include "../inputs/interfaces/command_interface.hpp"
#include "../views/interfaces/view_interface.hpp"
#include "../common/interfaces/iowrapper_interface.hpp"
#include "../models/app.hpp"
#include "../../include/controllers/game_process.hpp"

class AppController{
    public:
        AppController(App*, IOWrapperInterface*);
        AppController(App*, CommandInterface*, ViewInterface*);
    private:
        bool handle_load(Command);
        bool handle_quit(Command);
        bool handle_game_over(Command);
        GameProcess* process;
        App* app;
        MenuController* load_menu_controller;
        MenuController* quit_menu_controller;
        MenuController* game_over_menu_controller;
        ViewInterface* view;
        CommandInterface* controller;
        void loop();
};

#endif //APP_CONTROLLER_H