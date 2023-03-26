#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
// using nampespace ariel




TEST_CASE("Initializiation."){
    Player p1("lidor");
    Player p2("someone");
    Player p3 ("bot");

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p3.cardesTaken() == 0);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p3.stacksize() == 26);

    CHECK_THROWS(Game (p1,p2)); 
    CHECK_THROWS(Game(p1,p3));
    CHECK_THROWS(Game(p2,p3));
    
};

TEST_CASE("Running a full game."){
    Player p1("lidor");
    Player p2("someone");
    Player p3 ("bot");

    Game game (p1,p2);
    game.playTurn(); // play just 1 round.
    CHECK(p1.cardesTaken() != 0);// don't know who won the round.
    CHECK(p2.cardesTaken() != 0);// don't know who won the round.
    CHECK(p1.stacksize() < 26);//don't know how many cards did he take.
    CHECK(p2.stacksize() < 26);//don't know how many cards did he take.
    CHECK(p1.stacksize() == p2.stacksize());

    game.printWiner(); // can't print winner since they played only 1 turn (assuming) || maybe somehow its possible

    game.playAll();
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
    CHECK(p1.stacksize() == 0);
    CHECK(p1.stacksize() == 0);

    Player p4("random");
    CHECK(p4.cardesTaken() == 0);
    CHECK(p4.stacksize() == 26);
    // need to restart the players p1 and p2
    p1.set_is_assigned_to_a_game();
    p2.set_is_assigned_to_a_game();

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK_THROWS(Game(p1,p4));
    CHECK_THROWS(Game(p2,p3));
    



}