#ifndef Barlog_h
#define Barlog_h
#include <string>
#include <iostream>
#include "Demon.h"
using namespace std;

//Balrog derived from demon
class Balrog :public Demon
{
public:
	Balrog();
	Balrog(int Hittingpoints_h, int Strengthpoints_s);
	int getHowmuchdamage();
	string getSpecies();
};
#endif