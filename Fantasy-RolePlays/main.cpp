#include <iostream>
#include <string>
#include "Creature.h"
#include "Demon.h"
#include "Elf.h"
#include "Human.h"
#include "Cyberdemon.h"
#include "Barlog.h"
using namespace std;

//Contains drivers to test class
//Create an object for each type of creature and repeatedly outputs the results of getDamage( )
int main()
{
	cout << "Welcome to the fantasy-role game" << endl;
	cout << "This game has four different creatures" << endl;
	cout << "Human, Cyberdemon, Balrog and Elf" << endl;
	cout << "Each creature has their own unique ability" << endl;
	cout << "LET THE ONE ROUND COMBAT BEGIN" << endl;
	cout << "" << endl;
	cout << "" << endl;

	Human human(10, 10);
	cout << human.getSpecies() << " ";
	cout << "Human damage:" << human.getHowmuchdamage() << endl;

	Cyberdemon cyberdemon(60, 70);
	cout << cyberdemon.getSpecies() << " ";
	cout << "Cyberdemon Damage:" << cyberdemon.getHowmuchdamage() << endl;

	Balrog balrog(80, 90);
	cout << balrog.getSpecies() << " ";
	cout << "Balrog Damage:" << balrog.getHowmuchdamage() << endl;
	
	Elf elf(40, 50);
	cout << elf.getSpecies() << " ";
	cout << "Elfs Damage:" << elf.getHowmuchdamage() << endl;
	
	return 0;
}