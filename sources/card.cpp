#include "card.hpp"
#include <string>
using namespace std;


// outline constructor
Card::Card(string kind, int value){
    this->kind_of_card = kind;
    this->card_value = value;
};