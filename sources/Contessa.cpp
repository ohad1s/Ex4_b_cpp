//
// Created by shira on 25/04/2022.
//
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
namespace coup{
    Contessa::Contessa(Game& g, std::string name) : Player(g, move(name)) {
    }

    Contessa::~Contessa(){}

    string Contessa::role() {
        return "Contessa";
    }

    void Contessa::block(Assassin& a){
        if (a.role()!="Assassin"){
            throw runtime_error("this player is not Assassin");
        }
        if (a.last_oper!="coup_3"){
            throw runtime_error("this player can not do it");
        }
        a.blocked->is_alive=true;
        this->game->num_of_players++;
    }
}