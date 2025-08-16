#pragma once
#include <iostream>
#include <string>

namespace color {
    inline const std::string reset   = "\033[0m";
    inline const std::string bold    = "\033[1m";
    inline const std::string red     = "\033[31m";
    inline const std::string green   = "\033[32m";
    inline const std::string yellow  = "\033[33m";
    inline const std::string blue    = "\033[34m";
    inline const std::string magenta = "\033[35m";
    inline const std::string cyan    = "\033[36m";
    inline const std::string white   = "\033[37m";

    inline void print(const std::string& text, const std::string& color_code) {
        std::cout << color_code << text << reset;
    }

    inline void println(const std::string& text, const std::string& color_code) {
        std::cout << color_code << text << reset << "\n";
    }

    // Prefixed color functions
    inline void err(const std::string& text)     { println("[X] "       + text, red); } // oh god no, an error
    inline void yay(const std::string& text)   { println("[Y] "       + text, green); } // pass!
    inline void warn(const std::string& text)  { println("[!!!] "     + text, yellow); } // warn
    inline void info(const std::string& text)    { println("[i] "       + text, blue); } // info
    inline void debug(const std::string& text) { println("[d] "       + text, magenta); } // Debug msg
    inline void debug_error(const std::string& text)    { println("[derr] "    + text, cyan); } // Debug err msg
}
