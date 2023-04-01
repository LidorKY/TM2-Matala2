#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Card{
    string kind_of_card;
    int card_value;
    string special_cards;

    public:
    /*--constructors--*/
    Card();// outline constructor.
    Card(string kind, int value, string special); // outline constructor. need to define it outside the class + use "this".
    // maybe need to add a destructor.
    /*----------------*/

    /*--functions--*/
    void print_card();
    /*-------------*/

};
