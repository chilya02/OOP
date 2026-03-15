#ifndef LOADER_H
#define LOADER_H

#include "../models/game.hpp"
#include "../../lib/json.hpp"

#include <fstream>

class Loader{
    public:
        Loader();
        ~Loader();
        Game* load();
        bool can_load();
    private:
        std::fstream file;
        nlohmann::json json;
        GameField* load_field();
        Player* load_player(GameField*);
        std::vector<Enemy*>* load_enemies(GameField*);
        EnemyBuilding* load_building(GameField*);
        void validate_fields(nlohmann::json, std::vector<const char*>);
        void read_file();
};

#endif // LOADER_H