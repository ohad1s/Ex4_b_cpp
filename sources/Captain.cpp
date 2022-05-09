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

namespace coup {
    int const ten=10;
    int const one=1;
    Captain::Captain(Game &g, std::string name) : Player(g, move(name)) {
        this->steal_from = NULL;
    }

    Captain::~Captain() {}

    string Captain::role() {
        return "Captain";
    }

    void Captain::block(Player &c) {
        this->role();
        if (c.role() != "Caption") {
            throw runtime_error("this player is not Caption");
        }
        if (c.last_oper != "steal") {
        } else if (c.last_oper != "steal_1") {
            c._coins--;
            this->steal_from->_coins++;
        } else if (c.last_oper != "steal_2") {
            c._coins -= 2;
            this->steal_from->_coins += 2;
        } else {
            throw runtime_error("this Player cant do this block");
        }
    }

    void Captain::steal(Player &p1) {
        if (this->coins() >= ten) {
            throw std::invalid_argument("must do coup");
        }
        if (this->game->num_of_players <= one) {
            throw std::invalid_argument("1 or less players");
        }
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        if (!p1.is_alive) {
            throw runtime_error("this player is dead");
        }
        if (p1._coins >= 2) {
            this->steal_from = &p1;
            p1._coins -= 2;
            this->_coins += 2;
            this->last_oper = "steal_2";
        } else if (p1._coins == one) {
            this->steal_from = &p1;
            p1._coins--;
            this->_coins++;
            this->last_oper = "steal_1";
        } else if (p1._coins!=0) {
            this->last_oper = "steal";
            this->steal_from = &p1;
        } else {
            throw runtime_error("coins=NEG");
        }
        this->game->_turn++;
        this->game->_turn %= this->game->p.size();
        if (!this->game->get_status()) { this->game->set_status(true); }
    }
}