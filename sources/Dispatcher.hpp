#pragma once
#include "Player.hpp"

namespace pandemic {

    class Dispatcher : public Player {

    public:
    
        Dispatcher(Board&, City);
        Player &fly_direct(City);
    };
}