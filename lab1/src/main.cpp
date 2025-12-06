#include "../include/common/game_process.hpp"
#include "../include/common/game.hpp"
#include "../include/ncurses/iowrapper.hpp"


int main(){
    Game* game = new Game();
    NcursesIOWrapper* io = new NcursesIOWrapper(game);
    GameProcess* game_process = new GameProcess(game, io);
    game_process->start();
    delete game_process;
    delete io;
    delete game;
}

