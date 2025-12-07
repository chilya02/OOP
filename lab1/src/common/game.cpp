#include "../../include/common/game.hpp"

#include <iostream>

Game::Game(int height, int width, int period){
    try{  
    this->field = new GameField(height, width);
    Cell* player_cell = &(*this->field->get_cell(height - 1, width - 1));
    this->player = new Player(player_cell);
    
    Cell* build_cell = &(*this->field->get_cell(0, 0));
    this->enemy_building = new EnemyBuilding(build_cell, period);

    this->enemies = new std::vector<Enemy*>;
    Cell* cell = this->field->get_cell(0, 1);
    Enemy* enemy = new Enemy(cell);
    this->enemies->push_back(enemy);

    this->weapon = new Weapon(this->player, this->field);
  }
  catch (const char* error_msg){
    std::cerr << error_msg << std::endl;
    exit(0);
  }
}

Game::~Game(){
  if (this->field)
    delete this->field;
  if (this->player)
    delete this->player;
  if (this->enemy_building)
    delete this->enemy_building;
  if (this->enemies)
    for (Enemy* enemy: *this->enemies)
      delete enemy;
    delete this->enemies;
  if (this->weapon)
    delete this->weapon;
}

Game* Game::create_random_game(){
  srand(time(NULL));
  int size = 10 + rand() % 16;
  return new Game(size, size);
}

Game* Game::create_user_game(){
    std::cout << "Enter field height" << std::endl;
    int height;
    std::cin >> height;
    std::cout << "Enter field width" << std::endl;
    int width;
    std::cin >> width;
    return new Game(width, height);
}