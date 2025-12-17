#ifndef Human_h
#define Human_h
#include <string>
#include <iostream>
#include "Creature.h"
using namespace std;

//Human derived from creature
class Human :public Creature
{
public:
	Human();
	Human(int new_Hitting_points, int new_Actual_Strength);
	string getSpecies();
	
};
#endif