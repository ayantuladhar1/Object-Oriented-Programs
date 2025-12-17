//Author: Ayan tuladhar
//Date: 12/04/2020

#ifndef WaterWar_h
#define WaterWar_h
#include <iostream>
using namespace std;

class WarOnWater
{

public:

    WarOnWater()
    {
        a = 0;
        b = 0;
        manipulation = 0;
        extentship = 0;
        number_of_ship = 0;
        attack = 0;
    };
    WarOnWater(char manipulate, int _a, int _b, int _extentofship, int _number_of_ship)
    {
        a = _a;
        b = _b;
        manipulation = manipulate;
        extentship = _extentofship;
        number_of_ship = _number_of_ship;
        attack = 0;
    };

    //Getters and Setters Function for ship orientation, numbers and attacks.
    string nameOftheShip(int _number_of_ship)
    {
        if (_number_of_ship == 7)
            return "Battleship";
        if (_number_of_ship == 6)
            return "Carrier";
        if (_number_of_ship == 5)
            return "Destroyer";
        if (_number_of_ship == 4)
            return "Cruiser";
        if (_number_of_ship == 3)
            return "Submarine";
    };

    int getextentofship() const
    {
        return extentship;
    };
    int getA()
    {
        return a;
    };
    int getB()
    {
        return b;
    };
    int getNum() const
    {
        return extentship;
    }
    int getattack()
    {
        return attack;
    }
    char getmanipulationofship() const
    {
        return manipulation;
    };

    void setmanipulationofship(char input)
    {
        if (input == 'h' || input == 'H')
            manipulation = 'h';
        else if (input == 'v' || input == 'V')
            manipulation = 'v';
        else
            manipulation = 'h';
    };
    void setA(int _a)
    {
        a = _a;
    };
    void setB(int  _b)
    {
        b = _b;
    }
    void increaseAttack()
    {
        attack = 1;
    };
    bool isSinking()
    {
        if (attack == 1)
            return true;
        else
            return false;
    };

protected:
    //Creates staring position for ships
    int a, b, number_of_ship, attack = 0, extentship;
    char manipulation;
};
#endif