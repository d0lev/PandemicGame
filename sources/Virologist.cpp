#include "Virologist.hpp"
using namespace pandemic;
using namespace std;

Virologist::Virologist(Board &board, City city) : Player(board, city,"Virologist"){}


Player &Virologist::treat(City name) {
    Color curr = board.getColor(name);
    if (currentCity == name) {return Player::treat(name);}
    if(!deck.at(curr).contains(name)) {throw invalid_argument {"This city doesnt belong to the player deck"};}
        board.setMorbidiy(name)--;
        deck.at(curr).erase(name);
        return *this;
    
}