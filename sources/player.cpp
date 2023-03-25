#include <iostream>
#include <stdio.h>
#include <string>
#include "player.hpp"
using namespace std;

// outline constructor.
Player::Player(string name){
    this->name_of_player = name;
    this->is_assigned_to_a_game = 0;
};

/*--outline functions--*/
int Player::stacksize(){
    return 26; // delete this value.
}
int Player::cardesTaken(){
    return 0; // delete this value.
}
/*---------------------*/