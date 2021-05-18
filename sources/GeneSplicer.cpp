#include "GeneSplicer.hpp"
using namespace pandemic;
using namespace std;

GeneSplicer::GeneSplicer(Board &board, City city) : Player(board, city,"GeneSplicer"){}


Player & GeneSplicer::discover_cure(Color name) {
        if(board.isDiscovered(name)) {return *this;}

        // check how much cards the player have
        uint numOfCards = 0;
        for (auto & cards : deck) {numOfCards += cards.second.size();}
        if(numOfCards < maxCards) {throw invalid_argument {"The player doesnt have 5 cards"};}
        if(!board.getResearchStation(currentCity)) {throw invalid_argument{"This city dosent have research station"};}
        board.setCure(name) = true; 

        set<City> cards;
        for (const auto & runner  : deck) {
              auto cities = runner.second;
              for (auto city : cities) {
                  cards.insert(city);
                  if(cards.size() == maxCards) {break;}
              }
        }

        for (auto city : cards) {
            auto curr = board.getColor(city);
            deck.at(curr).erase(city);
        }

        return *this;
}