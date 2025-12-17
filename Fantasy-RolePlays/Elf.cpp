#include <iostream>
#include <string>
#include "Elf.h"
using namespace std;

//Elf derived from creature
Elf::Elf() : Creature()
{}

//New Types, Strength, Hit points etc. are initialized to elf
//Includes appropriate mutator and accessor funtion

Elf::Elf(int new_Hittingpoints, int new_Strengthpoints)
    : Creature(new_Hittingpoints, new_Strengthpoints)
{}

//Elves have a 10% chance to inflict a magical attack that doubles the normal amount of damage
//Elves inflict double magical damage with a 10% chance
int Elf::getHowmuchdamage()
{
    int damage;
    damage = (rand() % getActualstrength()) + 1;
    cout << "attacks for " << damage << " points!" << endl;
    if (rand() % 10 == 0)
    {
        damage = damage * 2;
        cout << "Magical attack inflicts " << damage << "additional damage points!" << endl;
        
    }
    return damage;
}

string Elf::getSpecies()
{
    return "Elf";
}
