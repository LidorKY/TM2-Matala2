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

Player p1_("");
Player p2_("");
Game::Game(): first_player(p1_),second_player(p2_){

}

Game::Game(Player &p1, Player &p2):first_player(p1),second_player(p2){
    if(this->first_player.get_is_assigned_to_a_game() == 1){
        throw invalid_argument("can't assign the first player since he is is already assigned to a game");
    }
    if(this->second_player.get_is_assigned_to_a_game() == 1){
        throw invalid_argument("can't assign the second player since he is is already assigned to a game");
    }
    this->first_player.set_is_assigned_to_a_game();
    this->second_player.set_is_assigned_to_a_game();
    initialize_deck_of_cards(); // working
    shuffle_cards(); //working
    deal_cards();// working
};


/*--outline functions--*/
void Game::playTurn(){
    if(this->first_player.name_of_player == this->second_player.name_of_player){
        throw invalid_argument("cant play because it is the same player.");
    }
    if(this->first_player.My_Cards_To_Play.size() == 0){
        throw invalid_argument("can't play another turn.");
        return;
    }
    Card temp1, temp2;
    temp1 = this->first_player.My_Cards_To_Play.back();
    temp2 = this->second_player.My_Cards_To_Play.back();
    if(temp1.card_value > temp2.card_value){
        if(temp1.card_value != 2 && temp2.card_value == 1){
            this->second_player.My_Cards_Taken.push_back(temp1);
            this->second_player.My_Cards_Taken.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
        else{
            this->first_player.My_Cards_Taken.push_back(temp1);
            this->first_player.My_Cards_Taken.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
    }
    else if(temp1.card_value < temp2.card_value){
        if(temp1.card_value == 1 && temp2.card_value != 2){
            this->first_player.My_Cards_Taken.push_back(temp1);
            this->first_player.My_Cards_Taken.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
        else{
            this->second_player.My_Cards_Taken.push_back(temp1);
            this->second_player.My_Cards_Taken.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back(); 
        }
    }
    // else{
    //     this->first_player.My_Cards_Taken.push_back(temp1);
    //     this->second_player.My_Cards_Taken.push_back(temp2);
    //     this->first_player.My_Cards_To_Play.pop_back();
    //     this->second_player.My_Cards_To_Play.pop_back(); 
    // }
    // else{
    //     while(temp1.card_value == temp2.card_value){
    //         this->on_the_table.push_back(temp1);
    //         this->on_the_table.push_back(temp2);
    //         this->first_player.My_Cards_To_Play.pop_back();
    //         this->second_player.My_Cards_To_Play.pop_back();
    //         if(this->first_player.My_Cards_To_Play.size() == 0){
    //             if(this->on_the_table.size() == 2){
    //                 return;
    //             }
    //             unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //             shuffle (this->on_the_table.begin(), this->on_the_table.end(), default_random_engine(seed));
    //             for(size_t i = 0; i < this->on_the_table.size(); i++){
    //                 Card temp;
    //                 temp = this->deck_of_cards.at(i);
    //                 if(i%2 ==0){
    //                     this->first_player.My_Cards_To_Play.push_back(temp);
    //                 }
    //                 else{
    //                     this->second_player.My_Cards_To_Play.push_back(temp);
    //                 }
    //             }
    //         }
    //         else{
    //             temp1 = this->first_player.My_Cards_To_Play.back();
    //             temp2 = this->second_player.My_Cards_To_Play.back();   
    //             this->on_the_table.push_back(temp1);
    //             this->on_the_table.push_back(temp2);  
    //             this->first_player.My_Cards_To_Play.pop_back();
    //             this->second_player.My_Cards_To_Play.pop_back(); 
    //         }
    //         if(this->first_player.My_Cards_To_Play.size() == 0){
    //             unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //             shuffle (this->on_the_table.begin(), this->on_the_table.end(), default_random_engine(seed));
    //             for(size_t i = 0; i < 52; i++){
    //                 Card temp;
    //                 temp = this->deck_of_cards.at(i);
    //                 if(i%2 ==0){
    //                     this->first_player.My_Cards_To_Play.push_back(temp);
    //                 }
    //                 else{
    //                     this->second_player.My_Cards_To_Play.push_back(temp);
    //                 }
    //             }
    //         }
    //         else{
    //             temp1 = this->first_player.My_Cards_To_Play.back();
    //             temp2 = this->second_player.My_Cards_To_Play.back();  
    //         }
    //     }
    //     Card temp3;
    //     if(temp1.card_value > temp2.card_value){
    //         this->on_the_table.push_back(temp1);
    //         this->on_the_table.push_back(temp2);  
    //         while(this->on_the_table.size() != 0){
    //             temp3 = this->on_the_table.back();
    //             this->first_player.My_Cards_Taken.push_back(temp3);
    //             this->on_the_table.pop_back();
    //         }
    //     }
    //     else{
    //         this->on_the_table.push_back(temp1);
    //         this->on_the_table.push_back(temp2);  
    //         while(this->on_the_table.size() != 0){
    //             temp3 = this->on_the_table.back();
    //             this->second_player.My_Cards_Taken.push_back(temp3);
    //             this->on_the_table.pop_back();
    //         } 
    //     }
    // }
}

void Game::printLastTurn(){

}

void Game::playAll(){
    while(this->first_player.My_Cards_To_Play.size() != 0){
        playTurn();
    }
    cout << this->first_player.stacksize() << "---hello1" << endl;
    cout << this->first_player.cardesTaken() << "---hello2" << endl;
    cout << this->second_player.stacksize() << "---hello3" <<  endl;
    cout << this->second_player.cardesTaken() << "---hello4" << endl;
}

void Game::printWiner(){
    if(this->first_player.My_Cards_Taken.size() > this->second_player.My_Cards_Taken.size()){
        cout << "the winner is the first player" << endl;
    }
    else if(this->first_player.My_Cards_Taken.size() < this->second_player.My_Cards_Taken.size()){
        cout << "the winner is the second player" << endl;
    }
    else{
        throw invalid_argument("there is a tie between the players.");
    }
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
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (this->deck_of_cards.begin(), this->deck_of_cards.end(), default_random_engine(seed));
}

void Game::deal_cards(){
    for(size_t i = 0; i < 52; i++){
        Card temp;
        temp = this->deck_of_cards.at(i);
        if(i%2 ==0){
            this->first_player.My_Cards_To_Play.push_back(temp);
        }
        else{
            this->second_player.My_Cards_To_Play.push_back(temp);
        }
    }
}
/*--------------------*/