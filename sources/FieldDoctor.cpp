#include "FieldDoctor.hpp"
using namespace pandemic;

FieldDoctor::FieldDoctor(Board &board, City city) : Player(board, city , "FieldDoctor"){}


Player & FieldDoctor::treat(City name) {
      
    if (currentCity == name) {return Player::treat(name);}
    if(board.getConnections(currentCity).contains(name)){
        City prev = currentCity;
        currentCity = name;
        Player::treat(currentCity);
        currentCity = prev;
        return *this;
    }
    throw invalid_argument {"illegal action: " + board.getCity(name)+ " is not connected to "+ board.getCity(currentCity)};
}