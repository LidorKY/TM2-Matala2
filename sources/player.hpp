#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class Player{
    public:
    
    string name_of_player; // this field is private.
    int is_assigned_to_a_game; // this field is private.
    int stack_size;
    int cards_taken;

    /*--constructors--*/
    Player();// outline constructor. 

    Player(string name); // outline constructor.
    // maybe need to add a destructor.
    /*----------------*/


    /*--functions--*/
    int stacksize(); // prints the amount of cards left. should be 21 but can be less if a draw was played.
    int cardesTaken(); // prints the amount of cards this player has won. 
    string get_name();
    int get_is_assigned_to_a_game() const {
        return is_assigned_to_a_game;
    }
    void set_is_assigned_to_a_game(){
        if(get_is_assigned_to_a_game() == 0){
            is_assigned_to_a_game = 1;
        }
        else{
            is_assigned_to_a_game = 0;
        }
    }
    /*-------------*/

};
