#include "game_process.hpp"

int main(){
    GameProcess game = GameProcess();
    game.create_user_game();

    game.start();
}

/*int main(int argc,char *argv[])
{
  // инициализация (должна быть выполнена 
  // перед использованием ncurses)
  initscr();

  // Измеряем размер экрана в рядах и колонках
  int row, col;
  getmaxyx(stdscr, row, col);
  
  //uперемещение курсора в стандартном экране
  move(row / 2, col / 2);

  //printw("Hello world"); // вывод строки
  refresh(); // обновить экран
  
  char c;
    c = getch(); // ждём нажатия символа
  endwin(); // завершение работы с ncurses
  std::cout<<c<<std::endl;
}*/
