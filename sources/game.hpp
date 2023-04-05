#pragma once
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <list>
using namespace std;

namespace ariel{
    // dont know yet if i need to fill here something.
};


class Game{
    public:

    Player &first_player; // the first player in the game.
    Player &second_player; // the first player in the game.
    vector <Card> deck_of_cards;
    vector <Card> on_the_table;
    list <string> print_last_turn;
    int num_of_rounds;
    double win1, win2, draw;

    Game();
    /*--constructors--*/
    Game(Player &player1, Player &player2); // outline constructor. need to define it outside the class + use "this".
    // maybe need to add a destructor.
    /*----------------*/


    /*--functions--*/
    void playTurn();
    void printLastTurn(); // print the last turn stats.
    void playAll(); //playes the game untill the end.
    void printWiner(); // prints the name of the winning player.
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn()).
    void printStats(); // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

    void print_deck_of_cards();
    void initialize_deck_of_cards();
    void shuffle_cards();
    void deal_cards();
    /*-------------*/

};
