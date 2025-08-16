#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <memory>
#include <optional>
#include <vector>
#include "Headers/rich.hpp"
using namespace color;

/*
    This file contains the main window drawing and such
    it is named main.cpp as of right now because this IS
    what is shown to the user

    all other things such as calculations and such can go
    in other files

    ty

    UNsincierely,
    TheRay17
*/



int main() {
    bool ok = true; // YES this is the fucking debug, YES im not a good enough programmer for this
    // disabled by default
    sf::RenderWindow window(sf::VideoMode({1600, 900}), "LibreNF", sf::Style::Titlebar | sf::Style::Close);
    window.setSize(sf::Vector2u(1600, 900));
/*  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 
    This Locks the window size, you can change as needed
    if need be, you can also create a pull request to add
    a way such that all drawn things aren't distorted when resized (please!!)
    doing this will also have to remove the window.setSize() function call.

    for those that need this to quickly work, change this value and
    the one in ```sf::VideoMode({xval, yval})```

    
*/
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 4;


    window.setVerticalSyncEnabled(true); 

    err("Potential font loading failure at this point! \n if the program spews out a lot of weird stuff, \n ensure you cloned the font, too!");
    ok ? debug_error("If the program exited, the failure is with the font!! Please git clone it or add your own AND editing the code to include it.") : void();
    // Font!!
    sf::Font main_font("./FONTS/CaskaydiaCoveNerdFont-Regular.ttf");
    yay("The font loaded successfully!");
    
    sf::Text watermark(main_font, "LibreNF, a free and open-source Nuclear Fission Simulator.", 12);
    watermark.setFillColor(sf::Color::Black);
    watermark.setPosition({0, 900-15});

    // store points to drawable items (glup)
    std::vector<std::unique_ptr<sf::Drawable>> drawables;
    drawables.push_back(std::make_unique<sf::Text>(watermark));



    bool window_focused = true; // yes were doing this :joy_cat:


    while (window.isOpen()) {
     
        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                yay("User closed window via alternative method");
                window.close();
            }

            if (event->is<sf::Event::FocusLost>()) {
                window_focused = false;
                ok ? debug("Window lost focus.") : void();
            }

            if (event->is<sf::Event::FocusGained>()) {
                window_focused = true;
                ok ? debug("Window gained focus.") : void(); // in line because im so cooool
            }
            
            /*
                You are probably why im making such a redundant
                bool variable, do not worry, this is just temporary for testing

                When this project starts growing bigger, expect 
                the check of the window being focused IN the event check.

                well i just figured out why i cant do this,
                once i enter the if (window_focused), loop, im stuck!

                commeneted.

                We will instead just skip to doing the check WITH the key press

            */

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && window_focused) {
//             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//              This part isi an example of checking for both conditions at the same.
                color::yay("User exited window via Escape key.");
                window.close();
            }

            //  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && window_focused) {
            //      color::info("User pressed space bro ");
            //      sf::CircleShape test(5.f);
            //      test.setFillColor(sf::Color::Red);
            //      test.setOutlineThickness(5.f);
            //      test.setOutlineColor(sf::Color::Blue);
            //      drawables.push_back(std::make_unique<sf::CircleShape>(test)); // <- Important line
            //      ok ? warn("A pointer was just made. Potentially unsafe!") : void();
            //  }
            // WORKS ^^^^

             // drawables.push_back(std::make_unique<sf::CircleShape>(test)); <- pushes shaped called test into drawables list as a pointer

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                void(); // Temp until classes are finshed
            }

        }

        window.clear(sf::Color::White);
        for (auto & drawable : drawables) {
            window.draw(*drawable);
        }
        window.display();

    }


}