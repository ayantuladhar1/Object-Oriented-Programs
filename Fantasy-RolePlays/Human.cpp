#include <iostream>
#include "Human.h"
#include <string>
using namespace std;


//Human derived from creature
Human::Human() :Creature()
{}

//New Types, Strength, Hit points etc. are initialized to human
//Includes appropriate mutator and accessor funtion
Human::Human(int new_Hitting_points, int new_Actual_Strength) :Creature(new_Hitting_points, new_Actual_Strength)
{}

string Human::getSpecies()
{
	return "Human";
}

