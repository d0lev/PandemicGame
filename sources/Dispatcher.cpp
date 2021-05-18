#include "Dispatcher.hpp"
using namespace pandemic;

Dispatcher::Dispatcher(Board &board, City city) : Player(board, city,"Dispatcher"){}


Player & Dispatcher::fly_direct(City name) { 
    if (board.getResearchStation(currentCity) && name != currentCity) { currentCity = name; return *this;} 
    return Player::fly_direct(name);
}
        