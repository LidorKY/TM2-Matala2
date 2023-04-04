#include <iostream>
#include <stdio.h>
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;

Player::Player(){ //default constructor - doesn't really needed here. //outline constructor.
    this->name_of_player = "don't use this constructor";
    this->is_assigned_to_a_game = 0;
} 

// outline constructor.
Player::Player(string name){
    this->name_of_player = name;
    this->is_assigned_to_a_game = 0;
    this->My_Cards_Taken.size();
    this->My_Cards_To_Play.size();
};

/*--outline functions--*/
int Player::stacksize(){
    if(this->is_assigned_to_a_game == 0){
        return 0;
    }
    else{
        return this->My_Cards_To_Play.size();
    }
}
int Player::cardesTaken(){
    if(this->is_assigned_to_a_game == 0){
        return 0;
    }
    else{
        return this->My_Cards_Taken.size();
    }
}

void Player::print_My_Cards_To_Play(){
    for(size_t i = 0; i <  this->My_Cards_To_Play.size(); i++){
        this->My_Cards_To_Play[i].print_card();
        cout << "\n" << endl;
    }
}
void Player::print_My_Cards_Taken(){
    for(size_t i = 0; i <  this->My_Cards_Taken.size(); i++){
        this->My_Cards_Taken.at(i).print_card();
        cout << "\n" << endl;
    }
}

int Player::get_is_assigned_to_a_game() const {
        return is_assigned_to_a_game;
    }

void Player::set_is_assigned_to_a_game(){
    if(get_is_assigned_to_a_game() == 0){
        is_assigned_to_a_game = 1;
    }
    else{
        is_assigned_to_a_game = 0;
    }
}
/*---------------------*/