#include "Medic.hpp"
using namespace pandemic;
using namespace std;

Medic::Medic(Board &board, City city) : Player(board, city,"Medic"){}


Player & Medic::treat(City name) {
    if(currentCity != name) {throw invalid_argument {"illegal action: you are not in "+board.getCity(name)};}
    if(board.getMorbidity(name) == 0) {throw invalid_argument {"illegal action: no more cubes remain in "+board.getCity(name)};}
    board.setMorbidiy(name) = 0;
    return *this;
}

Player & Medic::drive(City name) {
    Color curr = board.getColor(name);
     if (board.isDiscovered(curr)) {
        board.setMorbidiy(name) = 0;
    }
    return Player::drive(name);
    
}

Player & Medic::fly_direct(City name) {
    Color curr = board.getColor(name);
     if (board.isDiscovered(curr)) {
        board.setMorbidiy(name) = 0;
    }
    return Player::fly_direct(name);
}

Player & Medic::fly_shuttle(City name) { 
    Color curr = board.getColor(name);
     if (board.isDiscovered(curr)) {
        board.setMorbidiy(name) = 0;
    }
    return Player::fly_shuttle(name);
}

Player & Medic::fly_charter(City name) {
    Color curr = board.getColor(name);
     if (board.isDiscovered(curr)) {
        board.setMorbidiy(name) = 0;
    }
    return Player::fly_charter(name);
}