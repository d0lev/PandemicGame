#include "Scientist.hpp"
#include<exception>
using namespace pandemic;
using namespace std;


Scientist::Scientist(Board &board, City city, int num = 4) : Player(board, city,"Scientist") {
    this->n = num;
}

Player & Scientist::discover_cure(Color name) {
        if(board.isDiscovered(name)) {return *this;}
        if(deck[name].size() < this->n) {throw invalid_argument {"The player doesnt have 4 cards wich have the same color"};}
        if(!board.getResearchStation(currentCity)) {throw invalid_argument{"This city dosent have research station"};}
        board.setCure(name) = true;
        uint removed = 1;
        for (auto city = deck.at(name).begin(); city != deck.at(name).end(); city ++) {
                if (removed == this->n) {break;}
                city = deck.at(name).erase(city);
                city ++;
                removed ++;
        }
        return *this;
}

