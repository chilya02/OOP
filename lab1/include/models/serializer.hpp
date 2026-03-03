#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "../../lib/json.hpp"
#include "game.hpp"

#include <fstream>

class Serializer{
    public:
        Serializer(Game* game);
        ~Serializer();
        void save();
    private:
        nlohmann::json json;
        Game* game;
        std::fstream file;
        void save_field();
        void save_player();
        void save_emenies();
        void save_enemy_building();
};

#endif  // SERIALIZER_H