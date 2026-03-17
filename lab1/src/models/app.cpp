#include "../../include/models/app.hpp"


App::App(){
    this->load_menu = new LoadMenu();
    this->quit_menu = new QuitMenu();
    this->loader = new Loader();
    if (!loader->can_load()){
        this->game = new Game();
        this->state = AppState::Play;
    } else {
        this->state = AppState::Load;
    }
}

App::~App(){
    if (this->game)
        delete this->game;
    if (this->loader)
        delete this->loader;
}

AppState App::get_state(){
    return this->state;
}

Game* App::get_game(){
    return this->game;
}

LoadMenu* App::get_load_menu(){
    return this->load_menu;
}

QuitMenu* App::get_quit_menu(){
    return this->quit_menu;
}