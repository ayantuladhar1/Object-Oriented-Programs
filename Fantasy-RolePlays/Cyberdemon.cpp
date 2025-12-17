#include <iostream>
#include "Cyberdemon.h"
#include "Demon.h"
using namespace std;

//Cyberdemon derived from demon
Cyberdemon::Cyberdemon(): Demon()
{}

//New Types, Strength, Hit points etc. are initialized to cyberdemon
//Includes appropriate mutator and accessor funtion
Cyberdemon::Cyberdemon(int Hittingpoints_h, int Strengthpoints_s): Demon(Hittingpoints_h, Strengthpoints_s)
{}

string Cyberdemon::getSpecies()
{
    return "Cyberdemon";
}

//Cyberdemons have a 5% chance of inflicting a demonic attack, which is an additional 50 damage points.
int Cyberdemon::getHowmuchdamage()
{
    int damage;
    damage = (rand() % getActualstrength()) + 1;
    cout << "attacks for " << damage << " points!" << endl;
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 additional additional damage Points!" << endl;
    }
    return damage;
}
