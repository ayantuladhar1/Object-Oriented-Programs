//Author: Ayan tuladhar
//Date: 12/04/2020

#include <iostream>
#include "Grid10_10.h"
#include "Waterwar.h"
#include "Board.h"
#include "Smartcomputer.h"
#include "Player.h"
#include <time.h>
#include <string>
using namespace std;


int main()
{
    int exit;
    char gameChoice;
    CurrentGrid Grid_example;
    cout << "Welcome to battleship game\n";
    cout << "Each player gets their own board\n\n";
    cout << "Instructions:\n";
    cout << "Players please enter letter for columns and number for rows to target opponenet's ship\n";
    cout << "If any player hits the opponent's ship, it's marked with 'O'\n";
    cout << "If any player miss the opponent's ship, it's marked as 'X'\n";
    cout << "If any ship is sunk, the messgae will be displayed on which ship got 'sunk'\n";
    cout << "The ships are placed on the board below after placement\n";

    //Prints the Grid
    Grid_example.printCurrentGrid();
    string input = "C";
    Board play;
    SmartComputer calculate;

    //Ask user to input a csv file.
    //cout << "To place your ships on board, please enter a filename:\n";
    //cout << "For a quick start, please enter 'tata.csv', Thank you!\n";
    play.getInformationofShip();
    cout << "\n";

    //Prints Player's grid with ships.
    cout << "PLAYER USES THE FOLLOWRING GRID: \n";
    play.getcurrent_grid().printCurrentGrid();
    cout << "SMART COMPUTER USES THE FOLLOWING GRID:\n";

    //Prints Smart Computer's grid with ships not visible to player.
    Grid_example.printCurrentGrid();
    cout << "\n";

    //Calculate random numbers
    calculate.getInformationofShip();
    cout << "\n";
    CurrentGrid calculaterCurrentGrid = calculate.getcurrent_grid();
    CurrentGrid userCurrentGrid = play.getcurrent_grid();

    do
    {
        int moveOn = 0;

        //Player shoots the opponenet.
        cout << "Player, please shoot the torperdo!\n";
        play.ShipsOnAttack(calculate.getcurrent_grid());
        calculate.getcurrent_grid().printUserAttackOnCurrentGrid(calculate.getcurrent_grid());

        //Smart Computer shoots the opponenet.
        cout << "SmartComputer shot it's torpedo\n";
        calculate.ShipsOnAttack(play.getcurrent_grid());

        //Checks if Smart Computer won the game.
        if (calculate.MaybeWinner())
        {
            cout << "Smart Computer won the game\n";
            input = "Q";
            cout << " \nDo you want to play the game again?(Y/N)";
            cin >> gameChoice;
            if (gameChoice == 'Y' || gameChoice == 'y')
            {
                input = "C";
                moveOn = 1; ;//this local variable will be used to skip the process of asking to quit the game
            }
            else
            {
                input = "Q";// input!=1 exit the game                              
                moveOn = 1;
            }

        }

        //Checks if player won the game.
        else
            if (play.MaybeWinner())
            {
                cout << "You won the game! Good job!\n";
                input = "Q";
                cout << " \nDo you want to play the game again?(Y/N)";
                cin >> gameChoice;
                if (gameChoice == 'Y' || gameChoice == 'y')
                {
                    return moveOn;
                    input = "C";//input=1 make the game start again

                }
                else
                {
                    input = "Q";// input!=1 exit the game
                    moveOn = 2;
                    cout << "\nPrevious Game Result:\n";
                    cout << "Player Grid with ship placed along with the mark of computer's torpedo.\n";
                    cout << "'O' is hit, 'X' is miss\n";
                    play.getcurrent_grid().printCurrentGrid();
                    cout << "Computer Grid with ship placed along with the mark of player's torpedo.\n";
                    cout << "'O' is hit, 'X' is miss\n";
                    calculate.getcurrent_grid().printCurrentGrid();
                    cout << "\nThank You! Bye!\n";
                }

            }
        if (moveOn == 1)
        {
            cout << "\nPrevious Game:\n";
            cout << "Player Grid with ship placed along with the mark of computer's torpedo.\n";
            cout << "'O' is hit, 'X' is miss\n";
            play.getcurrent_grid().printCurrentGrid();
            cout << "Computer Grid with ship placed along with the mark of player's torpedo.\n";
            cout << "'O' is hit, 'X' is miss\n";
            calculate.getcurrent_grid().printCurrentGrid();
            cout << "\nWell then lets play the game again.\n\n";
        }
        else if (moveOn == 2)
        {
            cout << "You let the computer win! Never do that again!" << endl;
        }
        else {
            do {
                //Option for player to quit the game or keep playing?
                cout << "Please enter C to keep playing or enter Q to quit the game\n";
                cout << "You can also enter 'H' for help\n";
                cin.ignore();
                cin >> input;
                if (cin.fail())
                {
                    cin.clear();

                    //Checks for invalid input
                    cout << "Input invalid please enter again!(C for yes, Q for no)\n";
                    exit = 1;
                }
                else if (input == "C" || input == "c")
                {
                    exit = 3;
                }
                else if (input == "H" || input == "h")
                {
                    cout << "Instructions:\n";
                    cout << "Players please enter letter for columns and number for rows to target your opponenet's ship\n";
                    cout << "If any player hits the opponent's ship, it's marked with color red O\n";
                    cout << "If any player miss the opponent's ship, it's marked as X\n";
                    cout << "If any ship is sunk, it will display the message which ship has been sunk\n";
                    exit = 3;
                }

                else if (input == "Q" || input == "q")
                {
                    exit = 3;
                    cout << "\n\nPrevious Game Result:\n";
                    cout << "Player Grid with ship placed along with the mark of computer's torpedo.\n";
                    cout << "'O' is hit, 'X' is miss\n";
                    play.getcurrent_grid().printCurrentGrid();
                    cout << "Computer Grid with ship placed along with the mark of player's torpedo.\n";
                    cout << "'O' is hit, 'X' is miss\n";
                    calculate.getcurrent_grid().printCurrentGrid();
                    cout << "\nThank You! Bye!\n";
                }
                else {
                    exit = 1;
                    cout << "\nInvalid option!\n";
                }
            } while (exit == 1);
        }

    } while (input == "H" || input == "h" || input == "C" || input == "c");
    system("pause");

    return 0;
    system("pause");

}