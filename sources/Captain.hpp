//
// Created by shira on 25/04/2022.
//

#ifndef CPP_EX4_A_CAPTAIN_H
#define CPP_EX4_A_CAPTAIN_H

#endif //CPP_EX4_A_CAPTAIN_H
namespace coup{
#pragma once
    class Captain : public Player {
    public:
        Player* steal_from;
        Captain(Game& g,string name);
        ~Captain();
        string role();
        void block(Player& p);
        void steal(Player& p1);
    };
}