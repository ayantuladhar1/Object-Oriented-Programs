/*Author: Ayan tuladhar
*Date: 12/04/2020
*Citation:
*CheggStudy(2018)ExpertQ&A[Source code].https://www.chegg.com/homework-help/questions-and-answers/project-develop-simple-battleship-game-battleship-guessing-game-two-players-played-four-gr-q27128229?trackid=C_PRelil
*/

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "Grid10_10.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Waterwar.h"
using namespace std;


//Uses Inheritance class for player.
//Creates board, uses exception handling, checks ships for their specified locations and provides inputs for attacks. 
class Board : public Player
{
public:
    Board()
    {
        //Left blank.
    };
    
    void getInformationofShip()
    {
        string ship, position, orient;
        int row, column;
        char charOrient;
        string file;
        int user;
        do 
        {
            try 
            {
                cout <<"Please choose from the following available files.\n";
                cout <<"To choose files please enter the number from 1 to 5\n";
                cout << "1 - tata\n";
                cout << "2 - tata1\n";
                cout << "3 - tata2\n";
                cout << "4 - tata3\n";
                cout << "5 - tata4\n";
                cin >> user;
                if (cin.fail()) 
                {
                    cin.clear();
                }
                if (user < 1 || user > 5) 
                {
                    throw user;
                }
                else if (user == 1)
                {
                    file = "tata.csv";
                }
                else if (user == 2)
                {
                    file = "tata1.txt"; 
                }
                else if (user == 3)
                { 
                    file = "tata2.txt";
                }
                else if (user == 4) 
                { 
                    file = "tata3.txt";
                }
                else
                { 
                    file = "tata4.txt";
                }
            }
            catch (int a)
            {
                cout << "Invalid user.\n";
            }
        } while (user != 1 && user != 2 && user != 3 && user != 4 && user != 5);
        cout << file << endl;

        ifstream infile(file);
        if (!infile)
        {
            cout << "File not found. Try entering again:\n";
            getInformationofShip();
        }
        else
        {
            string str("");
            cout << "Please enter 'start' to start the game:\n"; //Start function to begin the game.
            while (str != "start")
            {
                getline(cin, str);
            }
        }
        {
            while (!infile.eof())
            {
                getline(infile, ship, ',');
                getline(infile, position, ',');
                getline(infile, orient);

                for (int a = 0; a < ship.length(); a++)
                {
                    ship[a] = tolower(ship[a]);
                }
                if (ship == "battleship")
                {
                    getInfoAboutShip(infile, position, orient, charOrient, row, column);
                    WarOnWater ble(charOrient, row, column + 1, 4, 7);
                    battle_ship = ble;
                    setBattleShip(ble, 7);
                }
                if (ship == "carrier")
                {
                    getInfoAboutShip(infile, position, orient, charOrient, row, column);
                    WarOnWater crr(charOrient, row, column + 1, 5, 6);
                    car_rier = crr;
                    setBattleShip(crr, 6);
                }
                if (ship == "destroyer")
                {
                    getInfoAboutShip(infile, position, orient, charOrient, row, column);
                    WarOnWater dst(charOrient, row, column + 1, 2, 5);
                    dest_royer = dst;
                    setBattleShip(dst, 5);
                }
                if (ship == "cruiser")
                {
                    getInfoAboutShip(infile, position, orient, charOrient, row, column);
                    WarOnWater cs(charOrient, row, column + 1, 3, 4);
                    crui_ser = cs;
                    setBattleShip(cs, 4);
                }
                if (ship == "submarine")
                {
                    getInfoAboutShip(infile, position, orient, charOrient, row, column);
                    WarOnWater sm(charOrient, row, column + 1, 3, 3);
                    sub_marine = sm;
                    setBattleShip(sm, 3);
                }
            }
        }
    };

    int changeCharToInt(char letter)
    {
        if (letter == 'a' || letter == 'A')
            return 1;
        if (letter == 'b' || letter == 'B')
            return 2;
        if (letter == 'c' || letter == 'C')
            return 3;
        if (letter == 'd' || letter == 'D')
            return 4;
        if (letter == 'e' || letter == 'E')
            return 5;
        if (letter == 'f' || letter == 'F')
            return 6;
        if (letter == 'g' || letter == 'G')
            return 7;
        if (letter == 'h' || letter == 'H')
            return 8;
        if (letter == 'i' || letter == 'I')
            return 9;
        if (letter == 'j' || letter == 'J')
            return 10;
        else
            return 11;
    };
    void getInfoAboutShip(ifstream& infile, string& location, string& manipulate, char& charorient, int& rows, int& columns)
    {
        stringstream ss;
        char letter = 'A';
        ss << location;
        ss >> letter;
        ss >> rows;
        ss.clear();
        ss << location;
        columns = letter - 'A';
        if (manipulate.size() != 0)
            charorient = manipulate[0];
    };
    void ShipsOnAttack(CurrentGrid& Smartcomputer)

    {
        bool isValid = true;
        char cool;
        int rows, columns;
        do
        {
            //Exception handling to fix errors
            try
            {
                cout << "Enter the letter of the column you want to shoot:\n";
                cin >> cool;
                cool = toupper(cool);
                if (cool != 'A' && cool != 'B' && cool != 'C' && cool != 'D' && cool != 'E' && cool != 'F' && cool != 'G' && cool != 'H' && cool != 'I' && cool != 'J')
                {
                    throw cool;

                }
            }
            catch (char e)
            {
                cout << e << "cannot shoot at that location\n";

            }
        } while (cool != 'A' && cool != 'B' && cool != 'C' && cool != 'D' && cool != 'E' && cool != 'F' && cool != 'G' && cool != 'H' && cool != 'I' && cool != 'J');
        do
        {
            try
            {
                cout << "Enter the number of the row that you want to shoot:\n";
                cin >> rows;
                if (rows != 1 && rows != 2 && rows != 3 && rows != 4 && rows != 5 && rows != 6 && rows != 7 && rows != 8 && rows != 9 && rows != 10)
                {
                    throw rows;
                }
            }
            catch (int f)
            {
                cout << f << "cannot shoot at that location\n";
            }
        } while (rows != 1 && rows != 2 && rows != 3 && rows != 4 && rows != 5 && rows != 6 && rows != 7 && rows != 8 && rows != 9 && rows != 10);
        columns = changeCharToInt(cool);
        while (!(rows >= 1 && rows <= 10))
        {
            isValid = false;
            cout << "Row doesn't exist, please enter number from 1-10: \n";
            cin >> rows;
        }
        while (!(columns >= 1 && columns <= 10))
        {
            isValid = false;
            cout << "Column doesn't exist, please enter letter from A-J: \n";
            cin >> cool;
            columns = changeCharToInt(cool);
        }
        if (cin.fail())
        {
            isValid = false;
            cin.clear();
            cout << "Please enter valid inputs\n";
        }
        cout << "-----------------------------------\n";
        cout << "If you hit, it will print O\n";
        cout << "If you miss, it will print X\n";
        cout << "If any ship sinks, it will print S\n";
        cout << "-----------------------------------\n";
        if (Smartcomputer.isAttack(rows - 1, columns - 1))
        {
            Smartcomputer.getVector()[rows - 1][columns - 1] = 1;
            cout << "Computer's ";
            int n = Smartcomputer.TooMAnyShipWhichOne(rows - 1, columns - 1);
            attackinprogress(Smartcomputer, n);
        }
    };
    void setBattleShip(WarOnWater& ship_name, int ship_number)
    {
        if (vec.setPositionofShip(ship_name, ship_number, ship_name.nameOftheShip(ship_number)))
        {
            cout << ship_name.nameOftheShip(ship_number) << " is ready and waiting for your command on grid\n";
        }
        else
        {
            cout << ship_name.nameOftheShip(ship_number) << " is not ready due to an error\n";
        }
    };
};
# endif