#pragma once
#include "Player.hpp"

namespace pandemic {

    class Scientist : public Player {

    private:
        int n;
        
    public:
    
        Scientist(Board &board, City city, int n);
        Player& discover_cure(Color);            
    };
}