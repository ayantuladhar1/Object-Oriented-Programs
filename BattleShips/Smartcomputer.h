/*Author: Ayan tuladhar
*Date: 12/04/2020
*Citation:
*CheggStudy(2018)ExpertQ&A[Source code].https://www.chegg.com/homework-help/questions-and-answers/project-develop-simple-battleship-game-battleship-guessing-game-two-players-played-four-gr-q27128229?trackid=C_PRelil
*/

#ifndef SmartComputer_h
#define SmartComputer_h
#include <iostream>
#include <stdlib.h>
#include "Grid10_10.h"
#include "Player.h"
using namespace std;


// Uses Inheritance class for player.
class SmartComputer : public Player
{

public:
    //Uses vector, generates random numbers, attacking opponent's ships and place ships for Smart computer.
    SmartComputer()
    {
        //Left blank.
    };
    CurrentGrid& getcurrent_grid()
    {
        return vec;
    };
    int Randomnumberforplayers()
    {
        return rand() % 10 + 1;

    };

    char Randommanipulationforplayers()
    {
        int random_manipulate = rand() % 2;
        char manipulate;

        if (random_manipulate == 0)
            manipulate = 'h';
        else
            manipulate = 'v';
        return manipulate;
    };
    void getInformationofShip()
    {
        int a = Randomnumberforplayers();
        int b = Randomnumberforplayers();

        //Place Battleship in random postion and provides four squares on grid.
        WarOnWater ble(Randommanipulationforplayers(), a, b, 4, 7);
        battle_ship = ble;
        setBattleShip(ble, 7);

        //Place Carrier in random position and provides five squares on grid.
        WarOnWater crr(Randommanipulationforplayers(), a, b, 5, 6);
        car_rier = crr;
        setBattleShip(crr, 6);
        a = Randomnumberforplayers();
        b = Randomnumberforplayers();

        //Place Destroyer in random position and provides two squares on grid.
        WarOnWater dst(Randommanipulationforplayers(), a, b, 2, 5);
        dest_royer = dst;
        setBattleShip(dst, 5);
        a = Randomnumberforplayers();
        b = Randomnumberforplayers();

        //Place Cruiser in random position and provides three sqaures on grid.
        WarOnWater cs(Randommanipulationforplayers(), a, b, 3, 4);
        crui_ser = cs;
        setBattleShip(cs, 4);
        a = Randomnumberforplayers();
        b = Randomnumberforplayers();

        //Place Submarine in random position and provides three squares on grid.
        WarOnWater sm(Randommanipulationforplayers(), a, b, 3, 3);
        sub_marine = sm;
        setBattleShip(sm, 3);
        a = Randomnumberforplayers();
        b = Randomnumberforplayers();

        //Prints after ship placement for smart computer.
        cout << "SmartComputer has placed it's ships\n\n";
    };

    void setVector(int a, int b, int attack)
    {
        CurrentGrid vector = this->getcurrent_grid();
        vector.getVector()[a][b] = attack;
    };
    void ShipisPlacable(WarOnWater& thisship, int whichship)
    {
        thisship.setA(Randomnumberforplayers());
        thisship.setB(Randomnumberforplayers());
        if (!vec.setPositionofShip(thisship, whichship, thisship.nameOftheShip(whichship)))
        {
            ShipisPlacable(thisship, whichship);
        }
    };
    void setBattleShip(WarOnWater& thisship, int randnumber)
    {
        if (!vec.setPositionofShip(thisship, randnumber, thisship.nameOftheShip(randnumber)))
        {
            ShipisPlacable(thisship, randnumber);
        }

    };
    void ShipsOnAttack(CurrentGrid& user_player)
    {
        int ship_number = 0, random_row = rand() % (10), random_column = rand() % (10);
        if (user_player.isAttack(random_row, random_column))
        {
            user_player.getVector()[random_row][random_column] = 1;
            cout << "Your ";
            int n = user_player.TooMAnyShipWhichOne(random_row, random_column);
            attackinprogress(user_player, n);
        }
        else
        {
            user_player.getVector()[random_row][random_column] = 2;
        }
        user_player.printCurrentGrid();
    };

};
#endif