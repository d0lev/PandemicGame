#include "Researcher.hpp"
using namespace pandemic;
using namespace std;

Researcher::Researcher(Board &board, City city) : Player(board, city,"Researcher"){}


Player &Researcher::discover_cure(Color name) {
        if(board.isDiscovered(name)) {return *this;}
        if(deck.at(name).size() < maxCards ) {throw invalid_argument {"The player doesnt have 5 cards wich have the same color"};}
        board.setCure(name) = true; 
        uint removed = 1;
        for (auto city = deck.at(name).begin(); city != deck.at(name).end(); city ++ ) {
                if(removed == maxCards) {break;}
                city = deck.at(name).erase(city);
                city ++;
                removed ++;
        }
        return *this;
}
     

