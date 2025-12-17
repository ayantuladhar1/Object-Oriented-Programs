#include <iostream>
#include "Barlog.h"
#include <string>
using namespace std;


//Balrog derived derived from demon
Balrog::Balrog(): Demon()
{}

//New Types, Strength, Hit points etc. are initialized to barlog
//Includes appropriate mutator and accessor funtion
Balrog::Balrog(int Hittingpoints_h, int Strengthpoints_s): Demon(Hittingpoints_h, Strengthpoints_s)
{}

string Balrog::getSpecies()
{
    return "Balrog";
}

// Balrogs are so fast they get to attack twice
//Inflicts more damage
int Balrog::getHowmuchdamage()
{
    int damage;
    damage = (rand() % getActualstrength()) + 1;
    cout << "attacks for " << damage << " points!" << endl;

    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 additional additional damage Points!" << endl;
    }
    int damage2;
    damage2 = (rand() % getActualstrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage = damage+damage2;
    return damage;
}