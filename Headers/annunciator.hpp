#pragma once
#include "rich.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace color;

/*
    File is meant for generating annuciator stuff

    Not sure if annuciators will be handled in annuciator.cpp or Main.cpp
    either way, good to have a header
*/

namespace annuciator {
    enum class Severity {
        Info = 0,
        Warning = 1,
        Error = 2,
        Trip = 3
    };

    enum class Light_Indicator {
        Off = 0,
        Flashing = 1,
        On = 2
    };

/*
    TODO:

    figure out how to make a blinking "light" in SFML

*/


class Annuciator {
    private:
        Severity severity; // <- refer to enum class Severity
        std::string name;
        std::string message;
        sf::Sound sound;
        bool active;
        Light_Indicator light_level; // <- refer to enum class Light_Indicator

    public:
        Annuciator(const std::string& name, Severity severity, const std::string& message, const sf::Sound sound, const Light_Indicator light_level)
            : severity(severity), name(name), message(message), sound(sound), light_level(light_level){}

        void trigger_annuciator() {
            if (!active) {
                active = true;
                severity > Severity::Warning ? err(message) : warn(message);
                sound.setLooping(true);
                sound.play();
            } else {
                err("Annuciator is already active.");
            }
        }

        // The next function already kind of serves as a force deactrivate

        void deactivate_annuciator() {
            if (active) {
                active = false;
                sound.setLooping(false);;
                info("Annuciator deactivated.");
            } else {
                warn("Annuciator was not active.");
            }
        }

        // Debug No audio trigger

        void force_trigger() {
            if (!active) {
                active = true;
                err(message);

            } else {
                err("Annuciator is already active.");
            }
       }

       // Works as a silence feature, too, but a different class will have to handle the light on the annuciator to continue flashing
       // nvm jsut realized i can save time by adding it to this

       void acknowledge() {
        if (!active) {
            err("Can not acknowledge annuciator that is not active.");
        } else {
            sound.setLooping(false);
            info("Annuciator " + name + " acknowleged");
            if (light_level != Light_Indicator::On && light_level == Light_Indicator::Flashing) {
                light_level = Light_Indicator::On;
            }
        }
       }

    };
} // <-- namespace annuciator