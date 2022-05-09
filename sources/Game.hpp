
#pragma once
#include "Player.hpp"
#include <vector>
#ifndef CPP_EX4_A_GAME_H
#define CPP_EX4_A_GAME_H
#endif //CPP_EX4_A_GAME_H
#include <string>
namespace coup {
    using namespace std;
    class Player;
    class Game {
    private:
        bool status;
    public:
        vector<Player*>p;
        Game();
        ~Game();
        int _turn;
        int num_of_players;
        vector <string> players();
        string winner();
        string turn();
        bool get_status()const;
        void set_status(bool s);
        void add_player(Player* p);
    };
}