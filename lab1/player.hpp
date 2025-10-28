#ifndef PLAYER_H
#define PLAYER_H

class Player{
  public:
    Player(int damage, int HP, int points = 0);
    bool is_alive();
    bool hit(int damage);
  private:
    int points_;
    int damage_;
    int HP_; // Health points
};

#endif //PLAYER_H
