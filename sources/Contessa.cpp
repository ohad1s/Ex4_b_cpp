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
    Contessa::Contessa(Game g, std::string name) : Player(g,name){}

    Contessa::~Contessa(){}

    string Contessa::role() {
        return "ohad";
    }

    void Contessa::block(Player p){
        cout<<"ohad"<<endl;
    }
}