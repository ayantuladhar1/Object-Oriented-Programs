*******************************************************
*  Name      :Ayan Tuladhar          
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program helps to create old fashioned board game known as "Battleship" which is a guessing game for two players
and in this case the players are Human and Computer. It is played on four grids two for each player where it's used to mark
each player's fleet of ships. Player's alternate turns by firing torpedoes at other player's ships. The objective of the game 
is to destroy the opposing player's entire fleet.



*******************************************************
*  Source files
*******************************************************


Name:  Main program.
   This is the main program which contains all the memebers form all the
   header files and also contains input/output, get/print functions and displays appropriate
   instructions and messages for the battleship game.

Name:  Waterwar.h
   This program creates different ship classes where it contains list of members and it is 
   organized by public and protected access specifier which includes get and set function 
   for Ship’s orientation, length, number, and number of hits. It also contains Boolean
   expression for Ship sink.	

Name: Board.h
   This program creates board class and inheritance class for player. It contains lists of
   members organized by access specifier public including members from “Grid10_10”, “Player”
   and “Waterwar” header files. It also includes operators/functions like string, fstream,
   sstream, Boolean expression and definition for ship’s attack, ship’s length, changing characters
   to integers and exception handling for input errors. In inheritance function the class inherit data
   members and member function. The fstream/sstream function is used to read and write lines from input
   files which in this case is csv file and allowing a string object to be treated as stream.

Name: Grid10_10.h
   This program creates grid class where it contains list of members organized by public and private
   access specifier including members form “Grid10_10” and “Waterwar” header files. It includes vector
   and string function for setting ships, printing grid, firing torpedoes, checking if ship is placeable
   and Boolean expressions. Vector creates the 10x10 board where Boolean checks whether ships are placeable
   on grid or not, if the shot is hit or miss, their orientation whether the ships are Horizontal or Vertical
   and prints grids for both player and computer.

Name: Player.h
   This program creates player class where it contains list of members organized by public and protected
   access specifier including members “Grid10_10” and “Waterwar” header files. It also includes get and set
   function for vector, get function to print information for ships and set function to set ships on grid for
   player. The Boolean expression checks if player has won the game and if/else statements to check which ship
   is under attack and prints the name.

Name: Smartcomputer.h
   This program creates computer class and inheritance class for player This program creates computer class where
   it contains list of members organized by public access specifier which includes get function for grids and ships,
   set function for vector and generates random numbers and orientations for ships to be placed. It also contains all
   the members from “Grid10_10” and “Player” header files. This program sets constructors which generates random numbers
   and orientations for ships to be placed.
      


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on Visual Studios g++.  It was 
   compiled, run, and tested on csegrid.ucdenver.pvt.

