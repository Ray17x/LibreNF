#include "rich.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
using namespace color;

/*
    This file is for making partical classes such as
    Neutrons, U235/238, etc.

    If you are adding a partical, add a class to THIS file so its easier to read

    you should also ensure that you add a void() (or maybe an int) function AFTER the class


    okay def an int function so we get an error code :tongue!:


    uh copy right stuff here 
*/

// NEUTRON // 
//fuck ts//

std::vector<sf::CircleShape> neutrons; // <- Mutuable neutron list

// class Thermal_Neutron {
//     int speed = 2.f;
//     int thickness = 5.f;

//     public:
//     int speed_x;
//     int speed_y;

//     void()
// };