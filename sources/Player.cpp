#include "Player.hpp"
#include <vector>
#include <exception>
using namespace pandemic;
using namespace std;


Player & Player::take_card(City name) {
    Color curr = board.getColor(name);
    deck.at(curr).insert(name);
    return *this;
}

Player & Player::drive(City name) {
        if(name == currentCity) {throw invalid_argument{"illegal action: cannot drive from current city to current city"};}
        if(!board.getConnections(currentCity).contains(name)) {
         throw invalid_argument {"illegal action: " + board.getCity(name)+ " is not connected to "+ board.getCity(currentCity)};
        }
        currentCity = name;
        return *this;
}

Player & Player::fly_direct(City name) {
        if(name == currentCity) {throw invalid_argument{"illegal action: cannot fly from current city to current city"};}
        Color curr = board.getColor(name);
        if(!deck.at(curr).contains(name)) {throw invalid_argument {"illegal action: you do not have the card of "+board.getCity(name)};}
        deck.at(curr).erase(name);
        currentCity = name;
        return *this;
}

Player & Player::fly_charter(City name) {
        if(name == currentCity) {throw invalid_argument{"illegal action: cannot fly from current city to current city"};}
        Color src = board.getColor(currentCity);
        if(!deck.at(src).contains(currentCity)) {throw invalid_argument {"illegal action: you do not have the "+board.getCity(currentCity)+" card"};}
        deck.at(src).erase(currentCity);
        currentCity = name;
        return *this;
}

Player & Player::fly_shuttle(City name) {
        if(name == currentCity) {throw invalid_argument{"illegal action: cannot fly from current city to current city"};}
        if(!(board.getResearchStation(currentCity) && board.getResearchStation(name))) {throw invalid_argument{"This city dosent have research station"};}
        currentCity = name;
        return *this;
}

Player & Player::build() {
    if(board.getResearchStation(currentCity)) {return *this;}
    Color curr = board.getColor(currentCity);
    if(!deck.at(curr).contains(currentCity)) {throw invalid_argument {"This city doesnt belong to the player deck"};}

    board.setResearchStation(currentCity) = true;
    deck.at(curr).erase(currentCity);
    return *this;
}


Player & Player::discover_cure(Color name) {
        if(board.isDiscovered(name)) {return *this;}
        if(deck.at(name).size() < maxCards ) {throw invalid_argument {"The player doesnt have 5 cards wich have the same color"};}
        if(!board.getResearchStation(currentCity)) {throw invalid_argument{"This city dosent have research station"};}
        board.setCure(name) = true; 
        uint removed = 0;
        if (deck.at(name).size() == maxCards) {deck.at(name).clear(); return *this;}
        for (auto city = deck.at(name).begin(); city != deck.at(name).end();) {
                if(removed == maxCards) {break;}
                city = deck.at(name).erase(city);
                ++city;
                ++removed;
        }
       
        return *this;
}


Player & Player::treat(City name) {
        if(currentCity != name) {throw invalid_argument {"illegal action: you are not in "+board.getCity(name)};}
        if(board.getMorbidity(name) == 0) {throw invalid_argument {"illegal action: no more cubes remain in "+board.getCity(name)};}
        Color curr = board.getColor(name);
        bool flag = board.isDiscovered(curr);
        if(flag) {board.setMorbidiy(name) = 0;}
        else {board.setMorbidiy(name)--;}
        return *this;

}
