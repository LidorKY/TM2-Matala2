#include <iostream>
#include <stdio.h>
#include <string>
#include "player.hpp"
using namespace std;

Player::Player(){ //default constructor - doesn't really needed here. //outline constructor.
    this->name_of_player = "don't use this constructor";
    this->is_assigned_to_a_game = 0;
    this->cards_taken = 0;
    this->stack_size = 0;
} 

// outline constructor.
Player::Player(string name){
    this->name_of_player = name;
    this->is_assigned_to_a_game = 0;
};

/*--outline functions--*/
int Player::stacksize(){
    if(this->is_assigned_to_a_game == 0){
        return 0;
    }
    else{
        return this->stack_size;
    }
}
int Player::cardesTaken(){
    if(this->is_assigned_to_a_game == 0){
        return 0;
    }
    else{
        return this->cards_taken;
    }
}
/*---------------------*/