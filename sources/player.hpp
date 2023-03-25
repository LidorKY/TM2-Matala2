#ifndef GAME_FLAG
#define GAME_FLAG
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class Player{
    string name_of_player = ""; // this field is private.
    int is_assigned_to_a_game; // this field is private.

    public:
    /*--constructors--*/
    Player(){ //default constructor - doesn't really needed here. //inline constructor.
        name_of_player = "don't use this constructor";
    } 

    Player(string name); // outline constructor. need to define it outside the class + use "this".
    // maybe need to add a destructor.
    /*----------------*/


    /*--functions--*/
    int stacksize(); // prints the amount of cards left. should be 21 but can be less if a draw was played.
    int cardesTaken(); // prints the amount of cards this player has won. 
    string get_name();
    int get_is_assigned_to_a_game(){
        return is_assigned_to_a_game;
    }
    void set_is_assigned_to_a_game(){
        is_assigned_to_a_game = 1;
    }
    /*-------------*/

};
#endif
