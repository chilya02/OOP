#include "../include/common/ncurses/iowrapper.hpp"
#include "../include/models/app.hpp"
#include "../include/controllers/app_controller.hpp"


int main(){
    App* app = new App();
    
    NcursesIOWrapper* io = new NcursesIOWrapper(app);
    AppController* controller = new AppController(app, io);
    
    delete controller;
    delete io;
    delete app;
}

