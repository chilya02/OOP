#include "../../include/models/serializer.hpp"
#include <iostream>


Serializer::Serializer(Game* game): game(game){
    this->file.open("data.json", std::ios::out);
}

Serializer::~Serializer(){
    this->file.close();
}

void Serializer::save(){
    save_field();
    save_player();
    save_enemy_building();
    save_emenies();
    file << this->json.dump(2);
}

void Serializer::save_field(){
    this->json["field"]["width"] = game->field->get_width();
    this->json["field"]["height"] = game->field->get_height();
    auto impassable_cells = nlohmann::json::array();
    auto slow_cells = nlohmann::json::array();

    for (int y = 0; y < game->field->get_height(); y++){
        for (int x = 0; x < game->field->get_width(); x++){
            Cell* cell = game->field->get_cell(y, x);
            if (cell->is_impassable()){
                auto obj = nlohmann::json::object();
                obj["y"] = y;
                obj["x"] = x;
                impassable_cells.push_back(obj);
            }
            if (cell->is_slow()){
                auto obj = nlohmann::json::object();
                obj["y"] = y;
                obj["x"] = x;
                slow_cells.push_back(obj);
            }
        }
    }

    this->json["field"]["impassable_cells"] = impassable_cells;
    this->json["field"]["slow_cells"] = slow_cells;
}

void Serializer::save_player(){
    this->json["player"]["y"] = game->player->get_cell()->get_y();
    this->json["player"]["x"] = game->player->get_cell()->get_x();
    this->json["player"]["HP"] = game->player->get_HP();
    this->json["player"]["score"] = game->player->get_score();
    this->json["player"]["coins"] = game->player->get_coins();
}

void Serializer::save_emenies(){
    auto  enemies =   nlohmann::json::array();
    for (Enemy* enemy: *game->enemies){
        auto obj = nlohmann::json::object();
        obj["x"] = enemy->get_cell()->get_x();
        obj["y"] = enemy->get_cell()->get_y();
        obj["HP"] = enemy->get_HP();
        enemies.push_back(obj);
    }
    this->json["enemies"] = enemies;
}

void Serializer::save_enemy_building(){
    this->json["enemy_building"]["y"] = game->enemy_building->get_cell()->get_y();
    this->json["enemy_building"]["x"] = game->enemy_building->get_cell()->get_x();

    this->json["enemy_building"]["period"] = game->enemy_building->get_period();
}