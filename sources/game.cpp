#include "game.hpp"
#include "player.hpp"
#include <stdexcept>


/*--outline constructor*/
Game::Game(Player &p1, Player &p2){
    if(p1.get_is_assigned_to_a_game() ==1){
        throw invalid_argument("can't assign the first player since he is is already assigned to a game");
    }
    if(p2.get_is_assigned_to_a_game() == 1){
        throw invalid_argument("can't assign the second player since he is is already assigned to a game");
    }
    // throw invalid_argument("delete this exception");
    this->first_player = p1;
    this->second_player = p2;
    p1.set_is_assigned_to_a_game();
    p2.set_is_assigned_to_a_game();
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
/*--------------------*/