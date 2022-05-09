//
// Created by shira on 25/04/2022.
//

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

namespace coup {
    Game::Game() {
        this->_turn = 0;
        this-> status = false;
        this->num_of_players=0;
    }

    Game::~Game() {}

    vector <string> Game::players() {
        vector <string> myvector;
        for (Player *pl : this->p) {
            if (pl->is_alive) {
                myvector.push_back(pl->name);
            }
        }
        return myvector;
    }

    string Game::turn() {
        while (!this->p[(unsigned int)(this->_turn)]->is_alive){
            this->_turn++;
            this->_turn%=this->p.size();
        }
        return this->p[(unsigned int)(this->_turn)]->name;
    }

    string Game::winner() {
        if (this->num_of_players>1){
            throw runtime_error("game still played");
        }
        if (!this->status)
        {
            throw runtime_error("the game does not start yet");
        }
        return this->turn();
    }

    bool Game::get_status() const {
        return this->status;
    }

    void Game::set_status(bool s) {
        this->status = s;
    }

    void Game::add_player(Player *p) {
        this->p.push_back(p);
        this->num_of_players++;
    }
}