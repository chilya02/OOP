#include "../include/enemies_controller.hpp"
#include "../include/cell.hpp"

#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <fstream>

EnemiesController::EnemiesController(std::vector<Enemy*>* enemies, Player* player, GameField* field)
  :enemies(enemies), player(player), field(field){}

void EnemiesController::act(){
  for (Enemy* enemy: *this->enemies){
    enemy->change_status();
    if (enemy->can_act())
      this->dijkstra(enemy);
  }
}

void EnemiesController::dijkstra(Enemy* enemy){
  const int MAX = this->field->size();

  int width = this->field->get_width();
  int height = this->field->get_height();
  
  std::map<Cell*, int> dist;
  std::queue<Cell*> q;
  
  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++){
      dist[field->get_cell(y, x)] = MAX;
    }
  }

  Cell* cell = player->get_cell();
  dist[cell] = 0;
  q.push(cell);

  while (!q.empty()){
    Cell* cur = q.front();
    q.pop();
    for (Cell* neighbor: cur->get_free_neighbors()){
      int weight = neighbor->is_slow() ? 2 : 1;
      if (dist[neighbor] > dist[cur] + weight){
        dist[neighbor] = dist[cur] + weight;
        q.push(neighbor);
      }
    }
  }
  
  Cell* target = nullptr;
  int min_length = MAX;
  for (Cell* neighbor: enemy->get_cell()->get_free_neighbors()){
    if (dist[neighbor] < min_length){
      min_length = dist[neighbor];
      target = neighbor;
    }
  }
  enemy->move(target);
}
