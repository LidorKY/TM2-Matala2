#include "card.hpp"
#include <string>
using namespace std;

// outline default constructor
Card::Card(){
    // no need to implement this
}

// outline constructor
Card::Card(string kind, int value, string special){
    this->kind_of_card = kind;
    this->card_value = value;
    this->special_cards = special;
};

void Card::print_card(){
    cout << "kind of card is: " << this->kind_of_card << endl;
    cout << "value of card is: " << this->card_value << endl;
    cout << "speciality of card is: " << this->special_cards << endl;
}