#include "../include/controllers/game_process.hpp"
#include "../include/models/game.hpp"
#include "../include/common/ncurses/iowrapper.hpp"
#include "../include/common/loader.hpp"

int main(){
    Loader* loader = new Loader();
    Game* game; 
    if (loader->can_load()){
        game = loader->load();
    } else {
        game = new Game();
    }
    NcursesIOWrapper* io = new NcursesIOWrapper(game);
    GameProcess* game_process = new GameProcess(game, io);
    game_process->start();
    delete game_process;
    delete io;
    delete game;
}

