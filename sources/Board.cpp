#include "Board.hpp"
#include <fstream>
using namespace std;

namespace pandemic { 


Board::Board() {
    ifstream map {"cities_map.txt"};
    initMap(map);
}

/**
 @brief : This function initializes the game map.
 the values ​​are stored in map data structure which contains the relationships between the cities.
 and also the color of the cities.
 @param map - text file containing all the necessary information **/

void Board::initMap(ifstream& map) {
    string source; string color; string destination;

    while (!map.eof()) {
        map >> source >> color;
        City src = getCity(source);
        Color clr = getColor(color);
        cities[src] = make_tuple(clr,0,false);
        cures[clr] = false;
        while (map.peek() != '\n' && !map.eof()) {
           map >> destination;
           City dest = getCity(destination);
           // insert the neighbour of the source city
           connections[src].insert(dest);
        }
    }
}

/**
 @param City
 @return color of the given city */

Color Board::getColor(City name) { return get<0> (cities[name]);}

/**
 @brief overloading [] operator
 @param City   
 @return reference to morbidity level */

int & Board::operator [] (City name) {return get<1> (cities[name]);}

/**
 @param City   
 @return morbidity level */

int Board::getMorbidity(City name) {return get<1> (cities[name]);}

/**
 @param City   
 @return reference to morbidity level */

int & Board::setMorbidiy(City name) {return get<1> (cities[name]);}

/**
 @param City   
 @return Boolean value for the presence of a research station */

bool Board::getResearchStation(City name) {return get<2> (cities[name]);}

/**
 @param City   
 @return reference to research station */

bool & Board::setResearchStation(City name) {return get<2> (cities[name]);}

/**
 @param City   
 @return Boolean value for the presence of a cure for the disease */

bool Board::isDiscovered(Color name) {return cures.at(name);}

/**
 @param City   
 @return reference to cure for the disease */

bool & Board::setCure(Color name) {return cures.at(name);}

/**
 @brief this function check if the board is clean from diseases */

bool Board::is_clean() {
    for (auto & city : cities) {
         City name = city.first;
         if (getMorbidity(name) != 0) {return false;}   
    }
    return true;
}

/**
 @param City   
 @return reference to set data structure that contains the neighbours */

set<City> & Board::getConnections(City name) {return connections.at(name);}

/**
 @brief This function removes all the dieseases in the board */ 

 void Board::remove_cures() {
     for (auto & disease : cures) {disease.second = false;}
 }

 /**
 @brief This function removes all the research stations in the board */ 

 void Board::remove_stations() {
     for (auto & runner : cities) {
         City current = runner.first;
         setResearchStation(current) = false;
        }
 }

/**
 @param string    
 @return enum value that representing the city name  */

City Board::getCity(const string& name) {return cities_table.at(name);}

/**
 @param string
 @return enum value that representing the city color */    

Color Board::getColor(const string& name) {return colors_table.at(name);}
    
/** 
 @param City 
 @return string that representing the city name */

string Board::getCity(City name) {
    string ret;
    for (const auto & runner : cities_table) {
            if(name == runner.second) {ret = runner.first; break;}
    }
    return ret;
}

/** 
 @param Color 
 @return string that representing the city color */

 string Board::getColor(Color name) {
    string ret;
    for (const auto & runner : colors_table) {
            if(name == runner.second) {ret = runner.first; break;}
    }
    return ret;
}

/**
 @brief this function create a column with length of the given input */

string Board::col(uint length) {
    string ret;
    for (int i = 0; i < length; i ++) {
        ret += " ";
    }
    return ret;
}


ostream & operator << (ostream & out, Board & b) {

     // print the diseases table
    out << "Disease Color \t\t is Cured\n\n";

    for (const auto & color : b.colors_table) {
        Color current = color.second;
        string record = b.getColor(current) + b.col(fcol - b.getColor(current).length()) + to_string(static_cast<int>(b.isDiscovered(current)));
        out << record << endl;
    } out << endl;

     // print the board table
    out << "City \t\t Diseases level \t Research labartory\n\n";
    for (const auto & cities : b.cities_table) {
        City current = cities.second;
        string record = b.getCity(current) + b.col(sfcol - b.getCity(current).length()) + to_string(b.getMorbidity(current)) + b.col(scol)  + to_string(static_cast<int>(b.getResearchStation(current)));
        out << record << endl;
    }
    return out;
 }

}

