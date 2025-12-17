#include "Creature.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;


string Creature::getSpecies()
{
	return "creature";
}

//Base class for creature created
//Hit and Stregtn points are initialized to creature
Creature::Creature()
{
	hittingpoints = 10;
	actualstrength = 10;
}

//New Types, Strength, Hit points etc. are initialized to creature
//Includes appropriate mutator and accessor funtion
Creature::Creature(int new_Hitting_points, int new_Actual_Strength)
{
	hittingpoints = new_Hitting_points;
	actualstrength = new_Actual_Strength;
}

//This inflicts one round of combat and returns the damage
int Creature::getHowmuchdamage()
{
	int damage;
	damage = (rand() % actualstrength) + 1;
	cout << "attacks for " << damage << " points!" << endl;
	return damage;
}

int Creature::gethittingPoints()
{
	return hittingpoints;
}

int Creature::getActualstrength()
{
	return actualstrength;
}

void Creature::setActualStrength(int Strengthpoints_s)
{
	actualstrength = Strengthpoints_s;
}

void Creature::setHittingpoints(int Hittingpoints_h)
{
	hittingpoints = Hittingpoints_h;
}














