#include "../../include/common/loader.hpp"

#include <iostream>
#include <format>

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

void Loader::read_file(){
    this->file >> this->json;
}

Game* Loader::load(){
    if (!this->can_load()){
        return nullptr;
    }
    this->read_file();
    GameField* field;
    Player* player;
    std::vector<Enemy*>* enemies;
    EnemyBuilding* building;
    Game* game;
    try{
        std::vector<const char*> fields = {"field", "player", "enemies", "enemy_building"};
        this->validate_fields(this->json, fields);
        field = load_field();
        player = load_player(field);
        enemies = load_enemies(field);
        building = load_building(field);
        game = new Game(field, player, enemies, building);
    } catch (const char* error_msg){
        std::cerr << error_msg << std::endl;
        exit(0);
    }
    return game;
}

GameField* Loader::load_field(){
    std::vector<const char*> fields = {"width", "height", "impassable_cells", "slow_cells"};
    this->validate_fields(this->json["field"], fields);
    int height = json["field"]["height"].get<int>();
    int width = json["field"]["width"].get<int>();
    GameField* field = new GameField(height, width, false);

    for (auto cell: json["field"]["impassable_cells"]){
        std::vector<const char*> fields = {"y", "x"};
        this->validate_fields(cell, fields);
        int y = cell["y"].get<int>();
        int x = cell["x"].get<int>();
        if (y < 0 || y >= field->get_height() || x < 0 || x >= field->get_width()){
            throw "Impassable cell coordinate out of range";
        }
        Cell** pointer = &(field->cells[y][x]);
        *pointer = new ImpassableCell(**pointer);
    }
    for (auto cell: json["field"]["slow_cells"]){
        std::vector<const char*> fields = {"y", "x"};
        this->validate_fields(cell, fields);
        int y = cell["y"].get<int>();
        int x = cell["x"].get<int>();
        if (y < 0 || y >= field->get_height() || x < 0 || x >= field->get_width()){
            throw "Slow cell coordinate out of range";
        }
        Cell** pointer = &(field->cells[y][x]);
        *pointer = new SlowCell(**pointer);
    }
    return field;
}

Player* Loader::load_player(GameField* field){
    std::vector<const char*> fields = {"x", "y", "HP", "coins", "score"};
    this->validate_fields(this->json["player"], fields);
    Player* player;
    int y = json["player"]["y"].get<int>();
    int x = json["player"]["x"].get<int>();
    Cell* player_cell = field->get_cell(y, x);
    if (!player_cell){
        throw "Player cell out of range";
    }
    int HP = json["player"]["HP"].get<int>();
    int score = json["player"]["score"].get<int>();
    int coins = json["player"]["coins"].get<int>();

    if (HP <= 0){
        throw "No enough HP";
    }

    if (score < 0){
        throw "Unexpected negative score for player";
    }

    if (coins < 0){
        throw "Unexpected negative conis for player";
    }
    player = new Player(player_cell, 30, HP, score, coins);
    return player;
}

std::vector<Enemy*>* Loader:: load_enemies(GameField* field){
    std::vector<Enemy*> *enemies = new std::vector<Enemy*>();
    for (auto enemy: json["enemies"]){
        std::vector<const char*> fields = {"y", "x", "HP"};
        this->validate_fields(enemy, fields);
        Cell* cell = field->get_cell(enemy["y"].get<int>(), enemy["x"].get<int>());
        int HP = enemy["HP"];
        if (!cell){
            throw "Enemy cell out of range";
        }
        if (HP <= 0){
            throw "Enemy HP not positive";
        }
        enemies->push_back(new Enemy(cell, 10, HP));
    }
    return enemies;
}

EnemyBuilding* Loader::load_building(GameField* field){
    std::vector<const char*> fields = {"y", "x", "period"};
    this->validate_fields(this->json["enemy_building"], fields);
    int y = json["enemy_building"]["y"].get<int>();
    int x = json["enemy_building"]["x"].get<int>();
    Cell* cell = field->get_cell(y, x);
    int period = json["enemy_building"]["period"].get<int>();
    if (!cell){
        throw "Enemy buidling coordinate out of range!";
    }
    if (period <= 0){
        throw "Enemy buidling period not positive";
    }
    EnemyBuilding* building = new EnemyBuilding(cell, period);
    return building;
}

void Loader::validate_fields(nlohmann::json json, std::vector<const char*> fields){
    for(const char* str: fields){
        if (!json.contains(str)){
            throw "Invalid json";
        }
    }
}