#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;


/*
this article help me to convert string to enum
https://stackoverflow.com/questions/7163069/c-string-to-enum */


namespace pandemic {

    const uint maxCards = 5;
    const uint fcol = 28;
    const uint sfcol = 23;
    const uint scol = 24;

    class Board {
    
    private:

    // the tuple contains the information of the city : <color,level of morbidity,research station>
    map <City,tuple<Color,int,bool>> cities;
    map <City,set<City>> connections;
    map <Color,bool> cures;


    public:
       Board();
       int & operator[](City);
       void initMap(ifstream&);
       City getCity(const string&);
       Color getColor(const string&);
       int getMorbidity(City);
       int & setMorbidiy(City);
       Color getColor(City);
       string getColor(Color);
       set<City> & getConnections(City);
       string getCity(City);
       bool & setResearchStation(City);
       bool getResearchStation(City);
       bool isDiscovered(Color);
       bool & setCure(Color);
       bool is_clean();
       void remove_cures();
       void remove_stations();
       static string col(uint);
       friend ostream & operator << (std::ostream& out, Board& b);

    const map<string,City> cities_table = {
                                                {"Algiers",City::Algiers},
                                                {"Atlanta",City::Atlanta},
                                                {"Baghdad",City::Baghdad},
                                                {"Bangkok",City::Bangkok},
                                                {"Beijing",City::Beijing},
                                                {"Bogota",City::Bogota},
                                                {"BuenosAires",City::BuenosAires},
                                                {"Cairo",City::Cairo},
                                                {"Chennai",City::Chennai},
                                                {"Chicago",City::Chicago},
                                                {"Delhi",City::Delhi},
                                                {"Essen",City::Essen},
                                                {"HoChiMinhCity",City::HoChiMinhCity},
                                                {"HongKong",City::HongKong},
                                                {"Istanbul",City::Istanbul},
                                                {"Jakarta",City::Jakarta},
                                                {"Johannesburg",City::Johannesburg},
                                                {"Karachi",City::Karachi},
                                                {"Khartoum",City::Khartoum},
                                                {"Kinshasa",City::Kinshasa},
                                                {"Kolkata",City::Kolkata},
                                                {"Lagos",City::Lagos},
                                                {"Lima",City::Lima},
                                                {"London",City::London},
                                                {"LosAngeles",City::LosAngeles},
                                                {"Madrid",City::Madrid},
                                                {"Manila",City::Manila},
                                                {"MexicoCity",City::MexicoCity},
                                                {"Miami",City::Miami},
                                                {"Milan",City::Milan},
                                                {"Montreal",City::Montreal},
                                                {"Moscow",City::Moscow},
                                                {"Mumbai",City::Mumbai},
                                                {"NewYork",City::NewYork},
                                                {"Osaka",City::Osaka},
                                                {"Paris",City::Paris},
                                                {"Riyadh",City::Riyadh},
                                                {"SanFrancisco",City::SanFrancisco},
                                                {"Santiago",City::Santiago},
                                                {"SaoPaulo",City::SaoPaulo},
                                                {"Seoul",City::Seoul},
                                                {"Shanghai",City::Shanghai},
                                                {"StPetersburg",City::StPetersburg},
                                                {"Sydney",City::Sydney},
                                                {"Taipei",City::Taipei},
                                                {"Tehran",City::Tehran},
                                                {"Tokyo",City::Tokyo},
                                                {"Washington",City::Washington},};
                                            

    const map<string,Color> colors_table = {
                                                {"Black",Color::Black},
                                                {"Blue",Color::Blue},
                                                {"Red",Color::Red},
                                                {"Yellow",Color::Yellow},};
        
    };
}