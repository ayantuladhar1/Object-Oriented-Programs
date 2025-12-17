#include <iostream>
#include "Demon.h"
#include <string>
using namespace std;



//Demon derived from creature
Demon::Demon() :Creature()
{}

//New Types, Strength, Hit points etc. are initialized to demon
//Includes appropriate mutator and accessor funtion
Demon::Demon(int Hittingpoints_h, int Strengthpoints_s): Creature(Hittingpoints_h, Strengthpoints_s)
{}

//Object invoke getDamage() for creature object 
int Demon::getHowmuchdamage()
{
	int damage;
	damage = (rand() % getActualstrength()) + 1;
	if ((rand() % 100) <= 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50" << "additional damage points!" << endl;
	}
	cout << "attacks for " << damage << " points!" << endl;
	return damage;
}

string Demon::getSpecies()
{
	return "Demon";
}