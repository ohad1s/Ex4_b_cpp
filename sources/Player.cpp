//
// Created by shira on 25/04/2022.
//
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

int const six = 6;
int const seven = 7;
namespace coup {
    Player::Player(Game &g, string name) {
        this->game = &g;
        this->name = move(name);
        if (this->game->num_of_players == six) {
            throw runtime_error("too many players");
        }
        if (this->game->get_status()) {
            throw runtime_error("game already start");
        }
        this->_coins = 0;
        this->last_oper = " ";
        this->is_alive = true;
        this->game->add_player(this);
    }

    Player::~Player() {}

    void Player::income() {
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        this->_coins++;
        this->last_oper = "income";
        this->game->_turn++;
        this->game->_turn%=this->game->num_of_players;
        if (!this->game->get_status()){this->game->set_status(true);}
    }

    void Player::foreign_aid() {
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        this->_coins += 2;
        this->last_oper = "foreign aid";
        this->game->_turn++;
        this->game->_turn%=this->game->num_of_players;
        if (!this->game->get_status()){this->game->set_status(true);}
    }

    void Player::coup(Player &p) {
        if (this->game->turn() != this->name) {
            throw std::invalid_argument("turn exception");
        }
        if (!p.is_alive) {
            throw runtime_error("this player is dead");
        }

        if (this->coins() < seven) {
            throw runtime_error("this Player does not have enough coins");
        }
        p.is_alive = false;
        this->_coins -= seven;
        this->game->num_of_players--;
        this->last_oper = "coup";
        this->game->_turn++;
        this->game->_turn%=this->game->num_of_players;
        if (!this->game->get_status()){this->game->set_status(true);}
    }

    string Player::role() { return "ohad"; }

    int Player::coins() {
        return this->_coins;
    }

}