#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "card.hpp"
#include <vector>
using namespace std;


class Player{
    public:

    string name_of_player; // this field is private.
    int is_assigned_to_a_game; // this field is private.
    vector <Card> My_Cards_To_Play;
    vector <Card> My_Cards_Taken;

    /*--constructors--*/
    Player();// outline constructor. 

    Player(string name); // outline constructor.
    // maybe need to add a destructor.
    /*----------------*/


    /*--functions--*/
    int stacksize(); // prints the amount of cards left. should be 21 but can be less if a draw was played.
    int cardesTaken(); // prints the amount of cards this player has won. 
    void print_My_Cards_To_Play();
    void print_My_Cards_Taken();
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
