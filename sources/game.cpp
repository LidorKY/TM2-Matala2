#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;


/*--outline constructor*/
Game::Game(Player &p1, Player &p2){
    if(p1.get_is_assigned_to_a_game() == 1){
        throw invalid_argument("can't assign the first player since he is is already assigned to a game");
    }
    if(p2.get_is_assigned_to_a_game() == 1){
        throw invalid_argument("can't assign the second player since he is is already assigned to a game");
    }

    this->first_player = p1;
    this->second_player = p2;
    p1.set_is_assigned_to_a_game();
    p2.set_is_assigned_to_a_game();

    initialize_deck_of_cards(); // working
    // print_deck_of_cards(); //working 
    shuffle_cards();
    print_deck_of_cards();




    deal_cards();
    p1.stack_size = 26;
    p2.stack_size = 26;
    
};


/*--outline functions--*/
void Game::playTurn(){

}

void Game::printLastTurn(){

}

void Game::playAll(){

}

void Game::printWiner(){

}

void Game::printLog(){

}

void Game::printStats(){

}

void Game::initialize_deck_of_cards(){
    for(int i = 1; i < 14; i++){
        if(i == 1){
            this->deck_of_cards.push_back(Card("clubs", i, "As"));
        }
        else if(i == 11){
            this->deck_of_cards.push_back(Card("clubs", i, "Jack"));
        }
        else if(i == 12){
            this->deck_of_cards.push_back(Card("clubs", i, "Queen"));
        }
        else if(i == 13){
            this->deck_of_cards.push_back(Card("clubs", i, "King"));
        }
        else{
            this->deck_of_cards.push_back(Card("clubs", i, "NULL"));
        }
    }
    for(int i = 14; i < 27; i++){
        if(i%13 == 1){
            this->deck_of_cards.push_back(Card("diamonds", i%13, "As"));
        }
        else if(i%13 == 11){
            this->deck_of_cards.push_back(Card("diamonds", 11, "Jack"));
        }
        else if(i%13 == 12){
            this->deck_of_cards.push_back(Card("diamonds", 12, "Queen"));
        }
        else if(i%13 == 0){
            this->deck_of_cards.push_back(Card("diamonds", 13, "King"));
        }
        else{
            this->deck_of_cards.push_back(Card("diamonds", i%13, "NULL"));
        }
    }
    for(int i = 27; i < 40; i++){
        if(i%13 == 1){
            this->deck_of_cards.push_back(Card("hearts", i%13, "As"));
        }
        else if(i%13 == 11){
            this->deck_of_cards.push_back(Card("hearts", i%13, "Jack"));
        }
        else if(i%13 == 12){
            this->deck_of_cards.push_back(Card("hearts", 12, "Queen"));
        }
        else if(i%13 == 0){
            this->deck_of_cards.push_back(Card("hearts", 13, "King"));
        }
        else{
            this->deck_of_cards.push_back(Card("hearts", i%13, "NULL"));
        }
    }
    for(int i = 40; i < 53; i++){
        if(i%13 == 1){
            this->deck_of_cards.push_back(Card("spades", i%13, "As"));
        }
        else if(i%13 == 11){
            this->deck_of_cards.push_back(Card("spades", 11, "Jack"));
        }
        else if(i%13 == 12){
            this->deck_of_cards.push_back(Card("spades", 12, "Queen"));
        }
        else if(i%13 == 0){
            this->deck_of_cards.push_back(Card("spades", 13, "King"));
        }
        else{
            this->deck_of_cards.push_back(Card("spades", i%13, "NULL"));
        }
    }
}

void Game::print_deck_of_cards(){
    for(size_t i = 0; i < 52; i++){
        this->deck_of_cards.at(i).print_card();
        cout << "\n" << endl;
    }
}

void Game::shuffle_cards(){
    // shuffle(begin(this->deck_of_cards), end(this->deck_of_cards), default_random_engine());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (this->deck_of_cards.begin(), this->deck_of_cards.end(), default_random_engine(seed));
}

void Game::deal_cards(){
    
}
/*--------------------*/