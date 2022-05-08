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

int const three = 3;
int const seven = 7;
namespace coup {
    Assassin::Assassin(Game g, std::string name) : Player(g, move(name)) {
        this->blocked = NULL;
    }

    Assassin::~Assassin() {}

    string Assassin::role() {
        return "Assassin";
    }

    void Assassin::coup(Player &p) {
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        if (!p.is_alive) {
            throw runtime_error("this player is dead");
        }
        if (this->_coins < three) {
            throw runtime_error("this Player does not have enough coins");
        }
        if (this->coins() >= seven) {
            p.is_alive = false;
            this->_coins -= seven;
            this->game->num_of_players--;
            this->last_oper = "coup";
            this->game->_turn++;
            this->game->_turn %= this->game->num_of_players;
            if (!this->game->get_status()) { this->game->set_status(true); }
        } else if (this->coins() >= three) {
            this->blocked = &p;
            p.is_alive = false;
            this->_coins -= three;
            this->game->num_of_players--;
            this->last_oper = "coup_3";
            this->game->_turn++;
            this->game->_turn %= this->game->num_of_players;
            if (!this->game->get_status()) { this->game->set_status(true); }
        }
    }
}
