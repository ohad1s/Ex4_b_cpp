#pragma once
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#ifndef CPP_EX4_A_PLAYER_H
#define CPP_EX4_A_PLAYER_H
#endif //CPP_EX4_A_PLAYER_H
namespace coup {
    using namespace std;

    class Game;
    class Player {
    protected:
        Game* game;
    public:
        string name;
        int _coins;
        string last_oper;
        bool is_alive;
        Player(Game& g,string name);
        ~Player();
        virtual void income();
        virtual void foreign_aid();
        virtual void coup(Player& p);
        virtual string role();
        virtual int coins();
    };
}