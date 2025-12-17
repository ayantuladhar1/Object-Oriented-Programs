#ifndef Creature_h
#define Creature_h
#include<iostream>
#include <string>
using namespace std;


//Started inheritence process
//Includes getters and setters
class Creature
{
private:
	int hittingpoints;
	int actualstrength;
	string getSpecies();
public:
	Creature();
	Creature(int new_Hittingpoint, int new_Strengthpoints);
	int getHowmuchdamage();
	int gethittingPoints();
	int getActualstrength();
	void setActualStrength(int Strength_s);
	void setHittingpoints(int Hittingpoint_h);

};
#endif