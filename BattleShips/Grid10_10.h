/*Author: Ayan tuladhar
*Date: 12/04/2020
*Citation:
*CheggStudy(2018)ExpertQ&A[Source code].https://www.chegg.com/homework-help/questions-and-answers/project-develop-simple-battleship-game-battleship-guessing-game-two-players-played-four-gr-q27128229?trackid=C_PRelil
*/

#ifndef GRID1_H
#define GRID1_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include "Waterwar.h"
#include "Grid10_10.h"
using namespace std;

class CurrentGrid
{

public:
    const int MAXIMUN_GRID = 10;
    //Using vector
    CurrentGrid()
    {
        shipNum = 999;
        v.resize(MAXIMUN_GRID, vector < int >(MAXIMUN_GRID, 0));
    };

    vector<vector<int>>& getVector()
    {
        return v;
    };

    //Functions for printing grid, setting ships, checking positions and randomly shooting torpedo for computer.
    int TooMAnyShipWhichOne(int a, int b)
    {
        v[a][b] = 1;

        return shipNum;
    };
    void printCurrentGrid()
    {
        for (int i = 0; i <= 10; i++) {
            vector<int> g;// creating a temporary vector
            for (int j = 0; j <= 10; j++) {
                g.push_back(0);//filling the temporary vector with blank space
            }
            v.push_back(g);
        }
        cout << "********************************************\n";
        cout << "********************************************\n";
        cout << "     A   B   C   D   E   F   G   H   I   J  \n";
        for (int x = 0; x < MAXIMUN_GRID; x++)
        {
            if (x + 1 == 10)
                cout << x + 1 << " ";
            else
                cout << " " << x + 1 << "  ";
            for (int y = 0; y < MAXIMUN_GRID; y++)
            {
                if (v[x][y] == 0)
                    cout << "  " << "  ";
                if (v[x][y] == 1)
                    cout << " O" << "  ";
                if (v[x][y] == 2)
                    cout << " X" << "  ";
                if (v[x][y] == 3)
                    cout << " S" << "  ";
                if (v[x][y] == 4)
                    cout << " C" << "  ";
                if (v[x][y] == 5)
                    cout << " D" << "  ";
                if (v[x][y] == 6)
                    cout << " A" << "  ";
                if (v[x][y] == 7)
                    cout << " B" << "  ";
            }
            cout << "" << endl;
        }
        cout << "********************************************\n";
        cout << "********************************************\n";
    };

    void printUserAttackOnCurrentGrid(CurrentGrid& computer)
    {
        vector<vector<int>> printVec = computer.getVector();
        cout << "********************************************\n";
        cout << "********************************************\n";
        cout << "     A   B   C   D   E   F   G   H   I   J  \n";
        for (int x = 0; x < MAXIMUN_GRID; x++)
        {
            if (x + 1 == 10)
                cout << x + 1 << " ";
            else
                cout << " " << x + 1 << "  ";
            for (int y = 0; y < MAXIMUN_GRID; y++)
            {

                if (printVec[x][y] == 0)

                    cout << "  " << "  ";
                if (printVec[x][y] == 1)

                    cout << " O" << "  ";

                if (printVec[x][y] == 2)
                    cout << " X" << "  ";
                if (printVec[x][y] == 3)
                    cout << "  " << "  ";
                if (printVec[x][y] == 4)
                    cout << "  " << "  ";
                if (printVec[x][y] == 5)
                    cout << "  " << "  ";
                if (printVec[x][y] == 6)
                    cout << "  " << "  ";
                if (printVec[x][y] == 7)
                    cout << "  " << "  ";


            }
            cout << "" << endl;
        }
        cout << "********************************************\n";
        cout << "********************************************\n";
    };


    bool setPositionofShip(WarOnWater& ship, int shipN, string name)
    {
        int i = ship.getA() - 1;
        int j = ship.getB() - 1;
        int shipLength = ship.getextentofship();
        int batA = i + shipLength;
        int batB = j + shipLength;
        bool enter = false;
        bool isPlaced = false;
        if (batA <= 10 && batB <= 10)
        {
            if (ship.getmanipulationofship() == 'h' || ship.getmanipulationofship() == 'H')
            {
                if (isCanshipbeplacable(ship, i, j, shipN))
                {
                    while (shipLength > 0)
                    {
                        v[i][j] = shipN;
                        j++;
                        shipLength--;
                    }
                    isPlaced = true;
                }
            }
            else if (ship.getmanipulationofship() == 'v' || ship.getmanipulationofship() == 'V')
            {
                if (isCanshipbeplacable(ship, i, j, shipN))
                {
                    while (shipLength > 0)
                    {
                        v[i][j] = shipN;
                        i++;
                        shipLength--;
                    }
                    isPlaced = true;
                }
            }
        }
        return isPlaced;
    };

    bool isCanshipbeplacable(WarOnWater& object, int a, int b, int shipN)
    {
        bool canPlace = false;
        if (object.getmanipulationofship() == 'H' || object.getmanipulationofship() == 'h')
        {
            for (int i = 0; i < object.getextentofship(); i++)
            {
                if (a >= 0 && a < 10 && b >= 0 && b < 10)
                {
                    if (v[a][b] != 0)
                    {
                        canPlace = false;
                        return canPlace;
                    }
                    else
                    {
                        canPlace = true;
                        b++;
                    }
                }
            }
        }
        else if (object.getmanipulationofship() == 'V' || object.getmanipulationofship() == 'v')
        {
            for (int i = 0; i < object.getextentofship(); i++)
            {
                if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                {
                    if (v[a][b] != 0)
                    {
                        canPlace = false;
                        return canPlace;
                    }
                    else
                    {
                        canPlace = true;
                        a++;
                    }
                }
            }
        }
        return canPlace;
    };

    bool isAttack(int a, int b)
    {
        if (v[a][b] == 7)
        {
            shipNum = 7;
            return true;
        }
        if (v[a][b] == 6)
        {
            shipNum = 6;
            return true;
        }
        if (v[a][b] == 5)
        {
            shipNum = 5;
            return true;
        }
        if (v[a][b] == 4)
        {
            shipNum = 4;
            return true;
        }
        if (v[a][b] == 3)
        {
            shipNum = 3;
            return true;
        }
        else
        {
            v[a][b] = 2;
            return false;
        }
    };

private:
    vector<vector<int>> v;
    int shipNum;
};
#endif