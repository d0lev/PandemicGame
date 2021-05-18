#pragma once
#include "Player.hpp"

namespace pandemic {
    class Medic : public Player {
    public:
        Medic(Board &, City);
        Player &treat(City);
        Player &drive(City);
        Player &fly_direct(City);
        Player &fly_shuttle(City);
        Player &fly_charter(City);
    };
}