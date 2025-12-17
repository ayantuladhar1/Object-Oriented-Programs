#ifndef Cyberdemon_h
#define Cyberdemon_h
#include <string>
#include <iostream>
#include "Demon.h"
using namespace std;

//Cyberdemon derived from demon
class Cyberdemon : public Demon
{
public:
	Cyberdemon();
	Cyberdemon(int Hittingpoints_h, int Strengthpoints_s);
	string getSpecies();
	int getHowmuchdamage();
};
#endif