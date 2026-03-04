#include "../../include/common/loader.hpp"

#include <iostream>

#include "../../include/models/cells/impassable_cell.hpp"
#include "../../include/models/cells/slow_cell.hpp"

Loader::Loader(){
    this->file.open("data.json", std::ios::in);
}

Loader::~Loader(){
    this->file.close();
}

bool Loader::can_load(){
    if (this->file)
        return true;
    return false;
}

Game* Loader::load(){
    nlohmann::json json;
    file >> json;
    GameField* field = new GameField(json["field"]["height"].get<int>(), json["field"]["width"].get<int>(), false);
    for (auto cell: json["field"]["impassable_cells"]){
        Cell** pointer = &(field->cells[cell["y"].get<int>()][cell["x"].get<int>()]);
        *pointer = new ImpassableCell(**pointer);
    }
    for (auto cell: json["field"]["slow_cells"]){
        Cell** pointer = &(field->cells[(int)cell["y"]][(int)cell["x"]]);
        *pointer = new SlowCell(**pointer);
    } 
    
    Cell* player_cell = field->get_cell(json["player"]["y"].get<int>(), json["player"]["x"].get<int>());
    Player* player = new Player(player_cell, 30, json["player"]["HP"].get<int>(), json["player"]["score"].get<int>(), json["player"]["coins"].get<int>());


    std::vector<Enemy*>* enemies = new std::vector<Enemy*>();
    
    for (auto enemy: json["enemies"]){
        Cell* cell = field->get_cell(enemy["y"].get<int>(), enemy["x"].get<int>());
        enemies->push_back(new Enemy(cell, 10, enemy["HP"]));
    }
    
    Cell* cell = field->get_cell((int)json["enemy_building"]["y"], (int)json["enemy_building"]["x"]);
    
    EnemyBuilding* building = new EnemyBuilding(cell, (int)json["enemy_building"]["period"]);

    Game* game = new Game(field, player, enemies, building);
    return game;
}