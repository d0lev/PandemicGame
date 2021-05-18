#include "OperationsExpert.hpp"
using namespace pandemic;

OperationsExpert::OperationsExpert(Board &board, City city) : Player(board, city,"OperationsExpert"){}

Player & OperationsExpert::build() {
    board.setResearchStation(currentCity) = true;
    return *this;
}
