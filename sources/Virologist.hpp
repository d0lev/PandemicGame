#pragma once
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Virologist : public Player {
        
    public:

        Virologist(Board &, City);
        Player &treat(City);
    };

}