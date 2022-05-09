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

using namespace std;
namespace coup {
    int const ten=10;
    Ambassador::Ambassador(Game& g, std::string name) : Player(g, move(name)) {
    }

    Ambassador::~Ambassador() {}

    string Ambassador::role() {
        return "Ambassador";
    }

    void Ambassador::transfer(Player &p1, Player &p2) {
        if (this->coins()>=ten){
            throw std::invalid_argument("must do coup");
        }
        if (this->game->num_of_players<=1) {
            throw std::invalid_argument("1 or less players");
        }
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        if (!p1.is_alive) {
            throw runtime_error("this player is dead");
        }
        if (!p2.is_alive) {
            throw runtime_error("this player is dead");
        }
        if (p1.coins() <= 0) {
            throw runtime_error("coins=NULL");
        }
        p1._coins -= 1;
        p2._coins += 1;
        this->last_oper = "transfer";
        this->game->_turn++;
        this->game->_turn %= this->game->p.size();
        if (!this->game->get_status()) { this->game->set_status(true); }
    }

   void Ambassador::block(Captain& c) {
        this->role();
        if (c.last_oper == "steal") {
        } else if (c.last_oper == "steal_1") {
            c._coins--;
            c.steal_from->_coins++;
        } else if (c.last_oper == "steal_2") {
            c._coins-=2;
            c.steal_from->_coins+=2;
        }
        else{
            throw runtime_error("this Player cant do this block");
        }
    }
}