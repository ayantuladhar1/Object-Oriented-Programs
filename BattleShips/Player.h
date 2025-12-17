/*Author: Ayan tuladhar
*Date: 12/04/2020
*Citation:
*CheggStudy(2018)ExpertQ&A[Source code].https://www.chegg.com/homework-help/questions-and-answers/project-develop-simple-battleship-game-battleship-guessing-game-two-players-played-four-gr-q27128229?trackid=C_PRelil
*/

#ifndef Player_h
#define Player_h
#include <iostream>
#include "Grid10_10.h"
#include "Waterwar.h"
using namespace std;


//Uses vector. 
//uses virtual void.
//Gets information for ships.
//Sets and attack ships for player.
class Player
{
public: //fucntion to set ships on grid for player
        //function to get information for ships
        //function to attacks ships
        //function to set vector at position x and y to 1(hit)
    CurrentGrid& getcurrent_grid()
    {
        return vec;
    };
    virtual void setBattleShip(WarOnWater&, int) = 0;
    virtual void getInformationofShip() = 0;
    virtual void ShipsOnAttack(CurrentGrid&) = 0;
    void setVector(int a, int b, int attackinprogress)
    {
        CurrentGrid vector = this->getcurrent_grid();
        vector.getVector()[a][b] = attackinprogress;
    };
    void attackinprogress(CurrentGrid& _currentgrid, int n)
    {
        if (n == 7)
        {
            cout << "\nBattleship is sunk\n";
            battle_ship.increaseAttack();

        }
        else if (n == 6)
        {
            cout << "\nCarrier is sunk\n";
            car_rier.increaseAttack();
        }
        else if (n == 5)
        {
            cout << "\nDestroyer is sunk\n";
            dest_royer.increaseAttack();
        }
        else if (n == 4)
        {
            cout << "\nCruiser is sunk\n";
            crui_ser.increaseAttack();
        }
        else if (n == 3)
        {
            cout << "\nSubmarine is sunk\n";
            sub_marine.increaseAttack();
        }
        else
        {
            cout << "ships under attack ";
        }

    };
    bool MaybeWinner()
    {
        if (sub_marine.getattack() == 1 && crui_ser.getattack() == 1 &&
            dest_royer.getattack() == 1 && car_rier.getattack() == 1 &&
            battle_ship.getattack() == 1)
        {
            return true;
        }

        else
        {
            return false;
        }

    };

protected:
    CurrentGrid vec;
    WarOnWater dest_royer;
    WarOnWater car_rier;
    WarOnWater battle_ship;
    WarOnWater sub_marine;
    WarOnWater crui_ser;
};
#endif