#include <iostream>
#include <stdio.h>
#include <string>
#include "player.hpp"
using namespace std;

// outline constructor.
Player::Player(string name){
    this->name_of_player = name;
};

/*--outline functions--*/
int Player::stacksize(){
    return 5; // delete this value.
}
int Player::cardesTaken(){
    return 5; // delete this value.
}
/*---------------------*/