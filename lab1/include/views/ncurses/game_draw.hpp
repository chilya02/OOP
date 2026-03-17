#ifndef GAME_DRAW_H
#define GAME_DRAW_H
#include "field_draw.hpp"
#include "hand_draw.hpp"
#include "progress_draw.hpp"
#include "interfaces/draw_interface.hpp"

class GameDraw: public IDraw{
    public: 
        GameDraw(Game*);
        ~GameDraw();
        void check_size() override;
        void invalidate() override;
    private:
        FieldDraw* field_drawer;
        HandDraw* hand_drawer;
        ProgressDraw* progress_drawer;
        bool is_visible;
        int col;
        int row;
        int field_x;
        int field_y;
        int min_width;
        int min_height;
        void draw();
        void print_size_message();
        void del_windows();
        void create_windows();
        bool calc_coordinates();
        void move_field();
};

#endif //GAME_DRAW_H