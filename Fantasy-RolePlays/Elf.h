#ifndef Elf_h
#define Elf_h
#include <string>
#include <iostream>
#include <cstdlib>
#include "Creature.h"
using namespace std;

//Elf derived from creature
class Elf :public Creature
{
public:
	Elf();
	Elf(int new_Hittingpoints, int new_Strengthpoints);
	int getHowmuchdamage();
	string getSpecies();
};
#endif