//
// Created by shira on 25/04/2022.
//
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#ifndef CPP_EX4_A_DUKE_H
#define CPP_EX4_A_DUKE_H

#endif //CPP_EX4_A_DUKE_H
namespace coup{
    class Duke : public Player {
    public:
        Duke(Game &g,string name);
        ~Duke();
        string role();
        void block(Player& p);
        void tax();
    };
}