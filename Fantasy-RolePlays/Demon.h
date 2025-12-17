#ifndef Demon_h
#define Demon_h
#include <string>
#include <iostream>
#include "Creature.h"
using namespace std;

//Demon derived from creature
class Demon :public Creature
{
public:
	Demon();
	Demon(int Hittingpoints_h, int Strengthpoints_h);
	int getHowmuchdamage();
	string getSpecies();

};
#endif