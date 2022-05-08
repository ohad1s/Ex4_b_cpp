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
namespace coup{
    Ambassador::Ambassador(Game g,std::string name) : Player(g,name){}
    Ambassador::~Ambassador(){}
    string Ambassador::role() {
        return "ohad";
    }
    void Ambassador::transfer(Player p1,Player p2){
        cout<<"ohad"<<endl;
    }
    void Ambassador::block(Captain c){
        cout<<"ohad"<<endl;
    }
}