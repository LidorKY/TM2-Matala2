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
#include <list>
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
    this->print_last_turn.clear();
    this->deck_of_cards.clear();
    this->on_the_table.clear();
    this->first_player.My_Cards_Taken.clear();
    this->first_player.My_Cards_To_Play.clear();
    this->second_player.My_Cards_Taken.clear();
    this->second_player.My_Cards_To_Play.clear();
    this->win1 = 0;
    this->win2 = 0;
    this->draw = 0;
    this->num_of_rounds = 0;
    initialize_deck_of_cards(); // working
    shuffle_cards(); //working
    deal_cards();// working
};


/*--outline functions--*/
void Game::playTurn(){
    if(&this->first_player == &this->second_player){
        throw invalid_argument("cant play because it is the same player.");
    }
    if(this->first_player.My_Cards_To_Play.size() == 0){
        throw invalid_argument("can't play another turn.");
        return;
    }
    Card temp1, temp2;
    temp1 = this->first_player.My_Cards_To_Play.back();
    temp2 = this->second_player.My_Cards_To_Play.back();
    // this->num_of_rounds++;
    string str1, str2;
    str1 = this->first_player.name_of_player + " has played " + to_string(temp1.card_value) + " of " + temp1.kind_of_card + ", ";
    str2 = this->second_player.name_of_player + " has played " + to_string(temp2.card_value) + " of " + temp2.kind_of_card + ". ";
    str1 = str1 + str2;
    if(temp1.card_value > temp2.card_value){
        if(temp1.card_value != 2 && temp2.card_value == 1){
            this->second_player.My_Cards_Taken.push_back(temp1);
            this->second_player.My_Cards_Taken.push_back(temp2);
            str1 = str1 + this->second_player.name_of_player + " won this round.\n";
            this->print_last_turn.push_back(str1);
            this->win2++;
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
        else{
            this->first_player.My_Cards_Taken.push_back(temp1);
            this->first_player.My_Cards_Taken.push_back(temp2);
            str1 = str1 + this->first_player.name_of_player + " won this round.\n";
            this->print_last_turn.push_back(str1);
            this->win1++;
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
    }
    else if(temp1.card_value < temp2.card_value){
        if(temp1.card_value == 1 && temp2.card_value != 2){
            this->first_player.My_Cards_Taken.push_back(temp1);
            this->first_player.My_Cards_Taken.push_back(temp2);
            str1 = str1 + this->first_player.name_of_player + " won this round.\n";
            this->print_last_turn.push_back(str1);
            this->win1++;
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
        }
        else{
            this->second_player.My_Cards_Taken.push_back(temp1);
            this->second_player.My_Cards_Taken.push_back(temp2);
            str1 = str1 + this->second_player.name_of_player + " won this round.\n";
            this->print_last_turn.push_back(str1);
            this->win2++;
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back(); 
        }
    }
    else{
        string str3, str4;
        str1 = str1 + " Draw. ";
        while(temp1.card_value == temp2.card_value){
            this->draw++;
            this->on_the_table.push_back(temp1);
            this->on_the_table.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
            size_t size = 0;
            size = this->on_the_table.size();
            if(this->first_player.My_Cards_To_Play.size() == 0){
                for(size_t i = 0; i < size; i++){
                    Card temporary;
                    temporary = this->deck_of_cards.at(i);
                    if(i%2 ==0){
                        this->first_player.My_Cards_Taken.push_back(temporary);
                    }
                    else{
                        this->second_player.My_Cards_Taken.push_back(temporary);
                    }
                }
                str1 = str1 + "1 last round ended in draw.\n";
                this->print_last_turn.push_back(str1);
                this->num_of_rounds++;
                return;
            }
            temp1 = this->first_player.My_Cards_To_Play.back();
            temp2 = this->second_player.My_Cards_To_Play.back();
            this->on_the_table.push_back(temp1);
            this->on_the_table.push_back(temp2);
            this->first_player.My_Cards_To_Play.pop_back();
            this->second_player.My_Cards_To_Play.pop_back();
            size_t size1 = 0;
            size1 = this->on_the_table.size();
            if(this->first_player.My_Cards_To_Play.size() == 0){
                for(size_t i = 0; i < size1; i++){
                    Card temporary1;
                    temporary1 = this->deck_of_cards.at(i);
                    if(i%2 ==0){
                        this->first_player.My_Cards_Taken.push_back(temporary1);
                    }
                    else{
                        this->second_player.My_Cards_Taken.push_back(temporary1);
                    }
                }
                str1 = str1 + "2 last round ended in draw.\n";
                this->print_last_turn.push_back(str1);
                this->num_of_rounds++;
                return;
            }
            temp1 = this->first_player.My_Cards_To_Play.back();
            temp2 = this->second_player.My_Cards_To_Play.back();
            str3 = this->first_player.name_of_player + " has played " + to_string(temp1.card_value) + " of " + temp1.kind_of_card + ", ";
            str4 = this->second_player.name_of_player + " has played " + to_string(temp2.card_value) + " of " + temp2.kind_of_card + ". ";
            str3 = str3 + str4;
            str1 = str1 + str3;
        }
        if(temp1.card_value > temp2.card_value){
            if(temp1.card_value != 2 && temp2.card_value == 1){
                this->second_player.My_Cards_Taken.push_back(temp1);
                this->second_player.My_Cards_Taken.push_back(temp2);
                str1 = str1 + this->second_player.name_of_player + " won this round.\n";
                this->print_last_turn.push_back(str1);
                this->win2++;
                this->first_player.My_Cards_To_Play.pop_back();
                this->second_player.My_Cards_To_Play.pop_back();
                Card helper1;
                while(this->on_the_table.size() != 0){
                    helper1 = this->on_the_table.back();
                    this->second_player.My_Cards_Taken.push_back(helper1);
                    this->on_the_table.pop_back();
                }
            }
            else{
                this->first_player.My_Cards_Taken.push_back(temp1);
                this->first_player.My_Cards_Taken.push_back(temp2);
                str1 = str1 + this->first_player.name_of_player + " won this round.\n";
                this->print_last_turn.push_back(str1);
                this->win1++;
                this->first_player.My_Cards_To_Play.pop_back();
                this->second_player.My_Cards_To_Play.pop_back();
                Card helper2;
                while(this->on_the_table.size() != 0){
                    helper2 = this->on_the_table.back();
                    this->first_player.My_Cards_Taken.push_back(helper2);
                    this->on_the_table.pop_back();
                }
            }
        }
        else{
            if(temp1.card_value == 1 && temp2.card_value != 2){
                this->first_player.My_Cards_Taken.push_back(temp1);
                this->first_player.My_Cards_Taken.push_back(temp2);
                str1 = str1 + this->first_player.name_of_player + " won this round.\n";
                this->print_last_turn.push_back(str1);
                this->win1++;
                this->first_player.My_Cards_To_Play.pop_back();
                this->second_player.My_Cards_To_Play.pop_back();
                Card helper3;
                while(this->on_the_table.size() != 0){
                    helper3 = this->on_the_table.back();
                    this->first_player.My_Cards_Taken.push_back(helper3);
                    this->on_the_table.pop_back();
                }
            }
            else{
                this->second_player.My_Cards_Taken.push_back(temp1);
                this->second_player.My_Cards_Taken.push_back(temp2);
                str1 = str1 + this->second_player.name_of_player + " won this round.\n";
                this->print_last_turn.push_back(str1);
                this->win2++;
                this->first_player.My_Cards_To_Play.pop_back();
                this->second_player.My_Cards_To_Play.pop_back(); 
                Card helper4;
                while(this->on_the_table.size() != 0){
                    helper4 = this->on_the_table.back();
                    this->second_player.My_Cards_Taken.push_back(helper4);
                    this->on_the_table.pop_back();
                }
            }
        }
    }
    this->num_of_rounds++;
}

void Game::printLastTurn(){
    cout << this->print_last_turn.back() << endl;
}

void Game::playAll(){
    while(this->first_player.My_Cards_To_Play.size() != 0){
        playTurn();
    }
}

void Game::printWiner(){
    if(this->first_player.My_Cards_Taken.size() > this->second_player.My_Cards_Taken.size()){
        cout << "the winner is: " << this->first_player.name_of_player << endl;
    }
    else if(this->first_player.My_Cards_Taken.size() < this->second_player.My_Cards_Taken.size()){
        cout << "the winner is: " << this->second_player.name_of_player << endl;
    }
    else{
        cout << "there is a tie between the players." << endl;
    }
}

void Game::printLog(){
    while(this->print_last_turn.size() != 0){
        cout << this->print_last_turn.front() << endl;
        this->print_last_turn.pop_front();
    }
}

void Game::printStats(){
    //win rate
    this->win1 = (this->win1/this->num_of_rounds)*100;
    cout << this->first_player.name_of_player << "'s win rate: " << to_string(this->win1) << "%.\n" << endl;
    this->win2 = (this->win2/this->num_of_rounds)*100;
    cout << this->second_player.name_of_player << "'s win rate: " << to_string(this->win2) << "%.\n" << endl;
    // cards won
    cout << this->first_player.name_of_player << " got: " << to_string(this->first_player.cardesTaken()) << " cards.\n" << endl;
    cout << this->second_player.name_of_player << " got: " << to_string(this->second_player.cardesTaken()) << " cards.\n" << endl;
    // amount of draws
    cout <<  "Amount of draws: " << to_string(this->draw) << ".\n" << endl;
    //draw rate 
    this->draw = (this->draw/this->num_of_rounds)*100;
    cout << "Draw rate: " << to_string(this->draw) << "%.\n" << endl;
    //amount of rounds
    cout << "Amount of rounds: " << to_string(this->num_of_rounds) << ".\n" << endl;
    
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