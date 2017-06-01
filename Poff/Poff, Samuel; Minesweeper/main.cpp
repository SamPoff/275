
/*
Author       : Sam Poff
Project Name : Minesweeper
Description  : This program reads from the file "Mines.txt" and creates a minesweeper board.
The player can then place flags or reveal locations.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
#include <locale>
#include <sstream>
#define ROWS 9
#define COLS 9

using namespace std;

int rowCol(int minesRow[], int minesCol[]);
void printGrid(char grid[][COLS], int minesLeft[]);
void reveal(char solutions[ROWS][COLS]);
void storeSolution(char grid[][COLS], char solutions[ROWS][COLS]);
void resetX(char grid[][COLS]);
string readInput(char grid[][COLS], int selection);
bool checkUserEntry(std::string answers[2], int minesRow[10], int minesCol[10], int minesLeft[1]);
int countNearbyMines(std::string answers[2], int minesRow[10], int minesCol[10]);
void amountOfMinesFeedback(char grid[][COLS], int amountOfMinesNear, std::string answers[2]);
void placeFlag(char grid[][COLS], int amountOfMinesNear, std::string answers[2]);
bool checkIfAllMinesFound(char grid[][COLS], int minesFound[1], char solutions[ROWS][COLS]);
void instructions();

    /**
    The main function in the program, controls level generation and menu selections.
    @param userInput - the user's input.
    @param entryCheck - boolean, tells if user hit mine.
    @param allMinesFound - boolean, tells if all the mines are flagged.
    @param solutions - an array holding all the solutions.
    @param grid - the grid which is displayed for the user.
    @param minesRow - the rows which contain mines.
    @param minesCol - the columns which contain mines.
    @param amountOfMinesNear - the amount of mines within one spot of the user.
    @param minesFound - the amount of mines found.
    @param answers - the grid spot that the user selected.
    */

int main()  {

    std::string answers[2];
    std::string userInput;
    bool dontQuit = true;
    bool entryCheck;
    bool allMinesFound;
    char solutions[ROWS][COLS] = {{0}};
    char grid[ROWS][COLS] = {{0}};
    int minesRow[10];
    int minesCol[10];
    int amountOfMinesNear = 0;
    int minesFound[1] = {0};
    int selection;
    int minesLeft[1];
    minesLeft[0] = 10;

    //generate level and solution file
    instructions();
    storeSolution(grid, solutions);
    resetX(grid);
    printGrid(grid, minesLeft);
    rowCol(minesRow, minesCol);

    //while loop keeps the program running until the user wants it to quit.
    while (dontQuit)  {

        bool fail = true;

        while (fail)  {

            if (cin >> selection)  {

                if (selection >= 1 && selection  <= 3)  {

                    fail = false;

                }//end if
                else  {

                    cout << "Invalid entry, please enter a number between 1 and 3." << endl;

                }//end else

            }//end if
            else  {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid entry, please enter a number between 1 and 3." << endl;

            }//end else

        }//end while

        //reveal
        if (selection == 1)  {

            //get user inputs
            userInput = readInput(grid, selection);

            //converts the user input from one string to two pieces of a string array.
            for (int i = 0; i < 2; i++)  {

                answers[i] = userInput[i];

            }//end for

            //returns true if player hit a mine
            entryCheck = checkUserEntry(answers, minesRow, minesCol, minesLeft);

            if (!entryCheck)  {

                //figure out how many mines are near.
                amountOfMinesNear = countNearbyMines(answers, minesRow, minesCol);
                amountOfMinesFeedback(grid, amountOfMinesNear, answers);
                allMinesFound = checkIfAllMinesFound(grid, minesFound, solutions);

                if (allMinesFound)  {

                    cout << "You found all the mines!" << endl;
                    minesLeft[0] = 0;
                    printGrid(solutions, minesLeft);

                }//end if
                else  {

                    printGrid(grid, minesLeft);

                }//end else

            }//end if
            else  {

                cout << "\nYou hit a mine!" << endl;
                reveal(solutions);
                dontQuit = false;

            }//end else

        }// end if

        //drop flag
        else if (selection == 2)  {

            //get user inputs / validates user input
            userInput = readInput(grid, selection);

            //converts the user input from one string to two pieces of a string array.
            for (int i = 0; i < 2; i++)  {

                answers[i] = userInput[i];

            }//end for

            amountOfMinesNear = countNearbyMines(answers, minesRow, minesCol);
            amountOfMinesFeedback(grid, amountOfMinesNear, answers);
            allMinesFound = checkIfAllMinesFound(grid, minesFound, solutions);

            if (allMinesFound)  {

                cout << "You found all the mines!" << endl;
                printGrid(solutions, minesLeft);

            }//end if
            else  {

                minesLeft[0] -= 1;
                placeFlag(grid, amountOfMinesNear, answers);
                printGrid(grid, minesLeft);

            }//end else

        }// end else if

        //quit game
        else if (selection == 3)  {

            dontQuit = false;

        }//end else if

    }//end while (dontQuit)

    return 0;

}//end main

    /**
    Takes in a 2d array and prints it in grid format.
    @param grid - the 2d array to be printed.
    @param minesLeft - the amount of mines left.
    */

void printGrid(char grid[ROWS][COLS], int minesLeft[0])  {

    cout << "\n  123456789";

    //iterate through and print all pieces of the grid.
    for (int i = 0; i < 9; i++)  {

        cout << "\n";

        if (i == 0)  {
            cout << "A ";
        }//end if
        else if (i == 1)  {
            cout << "B ";
        }//end if
        else if (i == 2)  {
            cout << "C ";
        }//end if
        else if (i == 3)  {
            cout << "D ";
        }//end if
        else if (i == 4)  {
            cout << "E ";
        }//end if
        else if (i == 5)  {
            cout << "F ";
        }//end if
        else if (i == 6)  {
            cout << "G ";
        }//end if
        else if (i == 7)  {
            cout << "H ";
        }//end if
        else if (i == 8)  {
            cout << "I ";
        }//end if

        for (int j = 0; j < 9; j++)  {

            cout << grid[i][j];

        }//end for

    }//end for

    cout << "\n\n" << "Minesweeper: " << endl;
    cout << "1. Reveal\n";
    cout << "2. Drop Flag\n";
    cout << "3. Quit\n";
    cout << "There are " << minesLeft[0] << " mines left." << endl;

}//end printGrid

    /**
    Stores the solution in a new 2d array called solutions.
    @param grid - the original 2d array of answers.
    @param file - file that holds the solutions.
    @param solutions - 2d array which mirrors the answers.
    */

void storeSolution(char grid[ROWS][COLS], char solutions[ROWS][COLS])  {

    //read the solution and save it to a solutions array.
    fstream file;
    file.open("C:\\Users\\Sam\\Desktop\\275\\MineSweeper\\Mines.txt", ios::in);
    if (file)  {

        for (int i = 0; i < 9; i++)  {

            for (int j = 0; j < 9; j++)  {

                file >> solutions[i][j];

            }//end for

        }//end for

    }//end if

    file.close();

}//end storeSolution

    /**
    Function to reset the grid to all x's.
    @param grid - original solution array, will be changed to all x's.
    */

void resetX(char grid[ROWS][COLS])  {

    //make the grid all 'x's again.
    for (int i = 0; i < 9; i++)  {

        for (int j = 0; j < 9; j++)  {

            grid[i][j] = 'X';

        }//end for

    }//end for

}//end resetX

    /**
    Function which will read, and validate the users input (their guess).
    @param fail - boolean which ensures input validation is not skipped.
    @return userInput - the user's letter number combination.
    @param invalid - dummy string to dump bad inputs.
    @param grid - the grid which is displayed for the user.
    */

string readInput(char grid[ROWS][COLS], int selection)  {

    string userInput;
    bool fail = true;
    std::string answers[2];

    while (fail)  {

        cout << "Enter row letter and  number: " << endl;

        if (cin >> userInput)  {

            std::string userInputCorrect(userInput);

            if (userInputCorrect[0] == 'A' ||
                userInputCorrect[0] == 'B' ||
                userInputCorrect[0] == 'C' ||
                userInputCorrect[0] == 'D' ||
                userInputCorrect[0] == 'E' ||
                userInputCorrect[0] == 'F' ||
                userInputCorrect[0] == 'G' ||
                userInputCorrect[0] == 'H' ||
                userInputCorrect[0] == 'I')  {


                if (userInputCorrect[1] == '1' ||
                    userInputCorrect[1] == '2' ||
                    userInputCorrect[1] == '3' ||
                    userInputCorrect[1] == '4' ||
                    userInputCorrect[1] == '5' ||
                    userInputCorrect[1] == '6' ||
                    userInputCorrect[1] == '7' ||
                    userInputCorrect[1] == '8' ||
                    userInputCorrect[1] == '9')  {

                    //converts the user input from one string to two pieces of a string array.
                    for (int i = 0; i < 2; i++)  {

                        answers[i] = userInput[i];

                    }//end for

                    int first;
                    int second;

                    if (answers[0] == "A")  {
                        first = 0;
                    }//end if
                    else if (answers[0] == "B")  {
                        first = 1;
                    }//end else if
                    else if (answers[0] == "C")  {
                        first = 2;
                    }//end else if
                    else if (answers[0] == "D")  {
                        first = 3;
                    }//end else if
                    else if (answers[0] == "E")  {
                        first = 4;
                    }//end else if
                    else if (answers[0] == "F")  {
                        first = 5;
                    }//end else if
                    else if (answers[0] == "G")  {
                        first = 6;
                    }//end else if
                    else if (answers[0] == "H")  {
                        first = 7;
                    }//end else if
                    else if (answers[0] == "I")  {
                        first = 8;
                    }//end else if
                    else  {
                        cout << "Something may be broken." << endl;
                    }//end else



                    if (answers[1] == "1")  {
                        second = 0;
                    }//end else if
                    else if (answers[1] == "2")  {
                        second = 1;
                    }//end else if
                    else if (answers[1] == "3")  {
                        second = 2;
                    }//end else if
                    else if (answers[1] == "4")  {
                        second = 3;
                    }//end else if
                    else if (answers[1] == "5")  {
                        second = 4;
                    }//end else if
                    else if (answers[1] == "6")  {
                        second = 5;
                    }//end else if
                    else if (answers[1] == "7")  {
                        second = 6;
                    }//end else if
                    else if (answers[1] == "8")  {
                        second = 7;
                    }//end else if
                    else if (answers[1] == "9")  {
                        second = 8;
                    }//end else if
                    else  {
                        cout << "Something may be broken." << endl;
                    }//end else

                    if (grid[first][second] == 'X')  {

                        fail = false;

                    }//end if
                    else  {

                        cout << "That spot has already been selected." << endl;

                    }//end else

                    /*
                    if (userInputCorrect[2] == 0)  {

                        fail = false;

                    }//end if
                    */

                }//end if

            }//end if
            else  {

                cout << "Invalid entry, please enter a letter between A and I," << endl;
                cout << "and a number between 1 and 9." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a letter between A and I," << endl;
            cout << "and a number between 1 and 9." << endl;

        }//end else

    }//end while

    return userInput;

}//end readInput

    /**
    Function to take the user input and let them know if they hit a mine.
    @param minesRow[] - all the rows which contain mines.
    @param minesCol[] - all the columns which contain mines.
    @param mineFound - boolean which is true if player hits a mine.
    @param first - the user's first entry (letter) converted to a number 0-8.
    @param second - the user's second entry (number).
    @param grid - the grid which is displayed for the user.
    */


bool checkUserEntry(std::string answers[2], int minesRow[10], int minesCol[10], int minesLeft[0])  {

    //check if user hit a mine.
    bool mineFound = false;
    int first;
    int second;

    if (answers[0] == "A")  {
        first = 0;
    }//end if
    else if (answers[0] == "B")  {
        first = 1;
    }//end else if
    else if (answers[0] == "C")  {
        first = 2;
    }//end else if
    else if (answers[0] == "D")  {
        first = 3;
    }//end else if
    else if (answers[0] == "E")  {
        first = 4;
    }//end else if
    else if (answers[0] == "F")  {
        first = 5;
    }//end else if
    else if (answers[0] == "G")  {
        first = 6;
    }//end else if
    else if (answers[0] == "H")  {
        first = 7;
    }//end else if
    else if (answers[0] == "I")  {
        first = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else



    if (answers[1] == "1")  {
        second = 0;
    }//end else if
    else if (answers[1] == "2")  {
        second = 1;
    }//end else if
    else if (answers[1] == "3")  {
        second = 2;
    }//end else if
    else if (answers[1] == "4")  {
        second = 3;
    }//end else if
    else if (answers[1] == "5")  {
        second = 4;
    }//end else if
    else if (answers[1] == "6")  {
        second = 5;
    }//end else if
    else if (answers[1] == "7")  {
        second = 6;
    }//end else if
    else if (answers[1] == "8")  {
        second = 7;
    }//end else if
    else if (answers[1] == "9")  {
        second = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else

    for (int i = 0; i < 10; i++)  {

        if (minesRow[i] == first && minesCol[i] == second)  {

            mineFound = true;

        }//end if

    }//end for

    return mineFound;

}//end checkUserEntry

    /**
    Function which will return an integer telling how many mines are touching the spot
    the user selected.
    @param answers[] - user's answer as a string array.
    @param first - user's letter guess converted to int.
    @param second - user's number guess converted back to int.
    @param minesRow[] - Rows which contain mines.
    @param minesCol[] - Columns which contain mines.
    @param counter - Keeps track of how many mines are near.
    @param grid - the grid which is displayed for the user.
    */

int countNearbyMines(std::string answers[2], int minesRow[10], int minesCol[10])  {

    //figure out how many mines are nearby.
    int first;
    int second;
    int counter = 0;

    if (answers[0] == "A")  {
        first = 0;
    }//end if
    else if (answers[0] == "B")  {
        first = 1;
    }//end else if
    else if (answers[0] == "C")  {
        first = 2;
    }//end else if
    else if (answers[0] == "D")  {
        first = 3;
    }//end else if
    else if (answers[0] == "E")  {
        first = 4;
    }//end else if
    else if (answers[0] == "F")  {
        first = 5;
    }//end else if
    else if (answers[0] == "G")  {
        first = 6;
    }//end else if
    else if (answers[0] == "H")  {
        first = 7;
    }//end else if
    else if (answers[0] == "I")  {
        first = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else



    if (answers[1] == "1")  {
        second = 0;
    }//end else if
    else if (answers[1] == "2")  {
        second = 1;
    }//end else if
    else if (answers[1] == "3")  {
        second = 2;
    }//end else if
    else if (answers[1] == "4")  {
        second = 3;
    }//end else if
    else if (answers[1] == "5")  {
        second = 4;
    }//end else if
    else if (answers[1] == "6")  {
        second = 5;
    }//end else if
    else if (answers[1] == "7")  {
        second = 6;
    }//end else if
    else if (answers[1] == "8")  {
        second = 7;
    }//end else if
    else if (answers[1] == "9")  {
        second = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else

    for (int i = 0; i < 10; i++)  {

        //checks the neighboring spots for mines.
        if (minesRow[i] == first && minesCol[i] + 1 == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] == first && minesCol[i] - 1 == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] + 1 == first && minesCol[i] == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] - 1 == first && minesCol[i] == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] + 1 == first && minesCol[i] + 1 == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] - 1 == first && minesCol[i] - 1 == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] + 1 == first && minesCol[i] - 1 == second)  {
            counter += 1;
        }//end if
        else if (minesRow[i] - 1 == first && minesCol[i] + 1 == second)  {
            counter += 1;
        }//end if

    }//end for

    return counter;

}//end contNearbyMines

    /**
    Function which will apply a number in the spot the user guessed.
    @param answers[] - user's answer as a string array.
    @param first - user's letter guess converted to int.
    @param second - user's number guess converted back to int.
    @param counter - Keeps track of how many mines are near.
    @param grid - The game board.
    */

void amountOfMinesFeedback(char grid[][COLS], int amountOfMinesNear, std::string answers[2])  {

    //apply the correct number in the spot the user selected to reveal.
    int first;
    int second;

    if (answers[0] == "A")  {
        first = 0;
    }//end if
    else if (answers[0] == "B")  {
        first = 1;
    }//end else if
    else if (answers[0] == "C")  {
        first = 2;
    }//end else if
    else if (answers[0] == "D")  {
        first = 3;
    }//end else if
    else if (answers[0] == "E")  {
        first = 4;
    }//end else if
    else if (answers[0] == "F")  {
        first = 5;
    }//end else if
    else if (answers[0] == "G")  {
        first = 6;
    }//end else if
    else if (answers[0] == "H")  {
        first = 7;
    }//end else if
    else if (answers[0] == "I")  {
        first = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else

    if (answers[1] == "1")  {
        second = 0;
    }//end else if
    else if (answers[1] == "2")  {
        second = 1;
    }//end else if
    else if (answers[1] == "3")  {
        second = 2;
    }//end else if
    else if (answers[1] == "4")  {
        second = 3;
    }//end else if
    else if (answers[1] == "5")  {
        second = 4;
    }//end else if
    else if (answers[1] == "6")  {
        second = 5;
    }//end else if
    else if (answers[1] == "7")  {
        second = 6;
    }//end else if
    else if (answers[1] == "8")  {
        second = 7;
    }//end else if
    else if (answers[1] == "9")  {
        second = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else

    if (amountOfMinesNear == 0)  {
        grid[first][second] = '0';
    }//end if
    else if (amountOfMinesNear == 1)  {
        grid[first][second] = '1';
    }//end else if
    else if (amountOfMinesNear == 2)  {
        grid[first][second] = '2';
    }//end else if
    else if (amountOfMinesNear == 3)  {
        grid[first][second] = '3';
    }//end else if
    else if (amountOfMinesNear == 4)  {
        grid[first][second] = '4';
    }//end else if
    else if (amountOfMinesNear == 5)  {
        grid[first][second] = '5';
    }//end else if
    else if (amountOfMinesNear == 6)  {
        grid[first][second] = '6';
    }//end else if
    else if (amountOfMinesNear == 7)  {
        grid[first][second] = '7';
    }//end else if
    else if (amountOfMinesNear == 8)  {
        grid[first][second] = '8';
    }//end else if
    else  {
        //You dun goofed, that's all.
    }

}//end amountOfMinesFeedback

    /**
    Function which will apply an 'F' in the spot the user selected.
    @param answers[] - user's answer as a string array.
    @param first - user's letter guess converted to int.
    @param second - user's number guess converted back to int.
    @param counter - Keeps track of how many mines are near.
    @param grid - The game board.
    */

void placeFlag(char grid[][COLS], int amountOfMinesNear, std::string answers[2])  {

    //output a flag in the location the user wants.
    int first;
    int second;

    if (answers[0] == "A")  {
        first = 0;
    }//end if
    else if (answers[0] == "B")  {
        first = 1;
    }//end else if
    else if (answers[0] == "C")  {
        first = 2;
    }//end else if
    else if (answers[0] == "D")  {
        first = 3;
    }//end else if
    else if (answers[0] == "E")  {
        first = 4;
    }//end else if
    else if (answers[0] == "F")  {
        first = 5;
    }//end else if
    else if (answers[0] == "G")  {
        first = 6;
    }//end else if
    else if (answers[0] == "H")  {
        first = 7;
    }//end else if
    else if (answers[0] == "I")  {
        first = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else



    if (answers[1] == "1")  {
        second = 0;
    }//end else if
    else if (answers[1] == "2")  {
        second = 1;
    }//end else if
    else if (answers[1] == "3")  {
        second = 2;
    }//end else if
    else if (answers[1] == "4")  {
        second = 3;
    }//end else if
    else if (answers[1] == "5")  {
        second = 4;
    }//end else if
    else if (answers[1] == "6")  {
        second = 5;
    }//end else if
    else if (answers[1] == "7")  {
        second = 6;
    }//end else if
    else if (answers[1] == "8")  {
        second = 7;
    }//end else if
    else if (answers[1] == "9")  {
        second = 8;
    }//end else if
    else  {
        cout << "Something may be broken." << endl;
    }//end else

    grid[first][second] = 'F';

}//end placeFlag

    /**
    Function which compares the users playing board with the solution.
    @param grid - user's board.
    @param solutions - the answers from the solution file.
    */

bool checkIfAllMinesFound(char grid[][COLS], int minesFound[1], char solutions[ROWS][COLS])  {

    //will return true if all mines have been found.
    bool allMinesFound = false;
    minesFound[0] = 0;

    fstream file;
    file.open("C:\\Users\\Sam\\Desktop\\275\\MineSweeper\\Mines.txt", ios::in);
    if (file)  {

        for (int i = 0; i < 9; i++)  {

            for (int j = 0; j < 9; j++)  {

                file >> solutions[i][j];

            }//end for

        }//end for

    }//end if

    file.close();

    for (int i = 0; i < 9; i++)  {

        for (int j = 0; j < 9; j++)  {

            if (grid[i][j] == 'F' && solutions[i][j] == 'O')  {

                minesFound[0] += 1;
                //cout << minesFound[0] << endl;

            }//end while

        }//end for

    }//end for

    if (minesFound[0] == 9)  {

        allMinesFound = true;

    }//end if

    return allMinesFound;

}//end checkIfAllMinesFound

    /**
    This function is a copy of the print function, minus the menu at the bottom.
    @param solutions - an array which holds the solutions unchanged.
    */

void reveal(char solutions[ROWS][COLS])  {

    //reveals the key. it is meant for debugging.
    cout << "\n  Key:\n  123456789";

    for (int i = 0; i < 9; i++)  {

        cout << "\n";

        if (i == 0)  {
            cout << "A ";
        }//end if
        else if (i == 1)  {
            cout << "B ";
        }//end if
        else if (i == 2)  {
            cout << "C ";
        }//end if
        else if (i == 3)  {
            cout << "D ";
        }//end if
        else if (i == 4)  {
            cout << "E ";
        }//end if
        else if (i == 5)  {
            cout << "F ";
        }//end if
        else if (i == 6)  {
            cout << "G ";
        }//end if
        else if (i == 7)  {
            cout << "H ";
        }//end if
        else if (i == 8)  {
            cout << "I ";
        }//end if

        for (int j = 0; j < 9; j++)  {

            cout << solutions[i][j];

        }//end for

    }//end for

}//end reveal

    /**
    Title and brief instructions.
    */

void instructions()  {

    cout << " _____ _____ _____ _____ _____ _ _ _ _____ _____ _____ _____ _____  " << endl;
    cout << "|     |     |   | |   __|   __| | | |   __|   __|  _  |   __| __  | " << endl;
    cout << "| | | |-   -| | | |   __|__   | | | |   __|   __|   __|   __|    -| " << endl;
    cout << "|_|_|_|_____|_|___|_____|_____|_____|_____|_____|__|  |_____|__|__| \n\n" << endl;

    cout << "This game will ask you to enter letter / number combinations." << endl;
    cout << "Ensure that you are using capitol letters, that both the" << endl;
    cout << "number and letter chosen are in the appropriate range, and" << endl;
    cout << "that there are no spaces." << endl;

}//end instructions

    /**
    Funtion which figures out which rows and columns the bombs are in.
    @param minesRow - Which rows contain mines.
    @param minesCol - Which columns contain mines.
    */

int rowCol(int minesRow[], int minesCol[])   {

    //gets the rows and columns of the mines.
    fstream file2;
    file2.open("C:\\Users\\Sam\\Desktop\\275\\MineSweeper\\mineLoc.txt", ios::in);
    if (file2)  {

        for (int i = 0; i < 10; i++)  {

            file2 >> minesRow[i];
            //cout << minesRow[i] << endl;

        }//end for

        for (int i = 0; i < 10; i++)  {

            file2 >> minesCol[i];
            //cout << minesCol[i] << endl;

        }//end for

    }//end if

    file2.close();

}//end rowCol
