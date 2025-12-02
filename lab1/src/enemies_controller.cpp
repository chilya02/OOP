#include "../include/enemies_controller.hpp"
#include "../include/cell.hpp"

#include <queue>
#include <map>

EnemiesController::EnemiesController(std::vector<Enemy*>* enemies, Player* player, GameField* field)
  :enemies(enemies), player(player), field(field){}

void EnemiesController::act(){
  for (Enemy* enemy: *this->enemies){
    enemy->change_status();
    if (enemy->can_act()){
      if (this->can_hit(enemy))
        this->player->hit(enemy->damage);
      else
        this->move_enemy(enemy);
    }
  }
}

bool EnemiesController::can_hit(Enemy* enemy){
  for (Cell* cell: enemy->get_cell()->get_neighbors()){
    if (cell == this->player->get_cell())
      return true;
  }
  return false;
}

std::map<Cell*, int>  EnemiesController::BFS(){
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

  Cell* cell = this->player->get_cell();
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
  return dist;
}

float EnemiesController::distance(Cell* cell){
  int y1 = cell->get_y();
  int x1 = cell->get_x();
  int y2 = this->player->get_cell()->get_y();
  int x2 = this->player->get_cell()->get_x();

  return sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
}

Cell* EnemiesController::get_optimal_cell(Enemy* enemy){
  std::map<Cell*, int> dist = this->BFS();
  Cell* target = nullptr;
  int min_length = this->field->size();
  for (Cell* neighbor: enemy->get_cell()->get_free_neighbors()){
    if (dist[neighbor] == min_length && target){
      if (distance(neighbor) < distance(target)){
        target = neighbor;
      }
    }
    if (dist[neighbor] < min_length){
      min_length = dist[neighbor];
      target = neighbor;
    }
  }
  return target;
}

void EnemiesController::move_enemy(Enemy* enemy){
  Cell* target = this->get_optimal_cell(enemy);
  enemy->move(target);
}
