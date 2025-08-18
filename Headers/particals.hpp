#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

// Neutron class definition
class Neutron {
private:
    float speed;
    bool thermal; // True == Thermal, False == Fast
    
public:
    Neutron(float spd, bool thrml) : speed(spd), thermal(thrml) {}

    float getSpeed() const { return speed; }
    bool isThermal() const { return thermal; }

    void setThermal(bool thrml) { thermal = thrml;}

    void make_neutron(float speed, bool thermal) {}
};

extern std::vector<Neutron> neutron_list;
extern std::vector<sf::CircleShape> neutrons_drawn; // <- Can be removed (as well as other drawn atoms) when no longer needed.

// Uranium class definition

class Uranium {
private:
    bool enriched; // True == Enriched, False == Depleted
    int isotope; // u235 = 235, u236 == 238, anything else is consider non-fissible
    float mass;

public:
    Uranium(bool enr, int iso, float m) : enriched(enr), isotope(iso), mass(m) {}

    bool isEnriched() const { return enriched; }
    int getIsotope() const { return isotope; }
    float getMass() const { return mass; }

    void setEnriched(bool enr) { enriched = enr; }
    void setIsotope(int iso) { isotope = iso; }
    void setMass(float m) { mass = m; }

    void make_uranium() {}
};

extern std::vector<Uranium> Uranium_list;
extern std::vector<sf::CircleShape> Uranium_drawn;

// General atoms (non-fissible)

class Atom {
private:
    int atomNo;
    float mass;
    int charge;
    int isotope;

public:
    Atom(int atNo, float m, int chg, int iso) : atomNo(atNo), mass(m), charge(chg), isotope(iso) {}

    int getAtomNo() const { return atomNo; }
    float getMass() const { return mass; }
    int getCharge() const { return charge; }
    int getIsotope() const { return isotope; }

    void setAtomNo(int atNo) { atomNo = atNo; }
    void setMass(float m) { mass = m; }
    void setCharge(int chg) { charge = chg; }
    void setIsotope(int iso) { isotope = iso; }

    void make_atom() {}
};

extern std::vector<Atom> Atom_list;
extern std::vector<sf::CircleShape> Atom_drawn;