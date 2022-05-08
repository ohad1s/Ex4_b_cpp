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
    Duke::Duke(Game &g, string name) : Player(g, move(name))
    {
    }
    Duke::~Duke(){}
    string Duke::role() {
        return "Duke";
    }

    void Duke::block(Player& p){
       if (p.last_oper=="foreign aid"){
           p._coins-=2;
       }
       else{
           throw invalid_argument("duke cant block this action");
       }
    }
    void Duke::tax(){
        if (this->coins()>=10){
            throw std::invalid_argument("must do coup");
        }
        if (this->game->num_of_players<=1) {
            throw std::invalid_argument("1 or less players");
        }
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        this->_coins+=3;
        this->last_oper = "tax";
        this->game->_turn++;
        this->game->_turn%=this->game->p.size();
        if (!this->game->get_status()){this->game->set_status(true);}
    }
}