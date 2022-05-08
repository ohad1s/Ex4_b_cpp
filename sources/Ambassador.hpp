//
// Created by shira on 25/04/2022.
//

#ifndef CPP_EX4_A_AMBASSADOR_H
#define CPP_EX4_A_AMBASSADOR_H
#include "Captain.hpp"
#endif //CPP_EX4_A_AMBASSADOR_H
namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game& g,string name);
        ~Ambassador();
        string role();
        void transfer(Player& p1,Player& p2);
        void block(Captain c);
    };
}