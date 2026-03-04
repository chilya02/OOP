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
};

#endif // LOADER_H