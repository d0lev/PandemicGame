
#pragma once
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"
#include <string>
#include <tuple>
#include <set>
using namespace std;
namespace pandemic {

    class Player {


    public:
    Board & board;
    map <Color,set<City>> deck = { {Color::Black,{}} , {Color::Blue,{}} , {Color::Red,{}} , {Color::Yellow,{}} };
    string name;
    City currentCity;


    public:
        Player(Board &b ,City c) :board(b),currentCity(c){}
        Player(Board & b, City c, string role): board(b),currentCity(c),name(role){};
        virtual Player & take_card(City);
        virtual Player & drive(City);
        virtual Player & fly_direct(City);
        virtual Player & fly_shuttle(City);
        virtual Player & fly_charter(City);
        virtual Player & discover_cure(Color);
        virtual Player & treat(City);
        virtual Player & build();
        string role() {return name;}

};
}