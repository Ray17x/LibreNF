#pragma once

#include <string>

class RPS_Channel {
private:
    bool trip_state;
    std::string trip_reason;
    std::string name;

public:
    RPS_Channel(const std::string& name);

    void trip(const std::string& reason);
    void reset();
    bool is_tripped() const;
    std::string get_trip_reason() const;
};