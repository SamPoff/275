
/*
Author       : Sam Poff
Project Name : LevelGeneratorProgram
Description  : This program creates the files "Mines.txt," and "minesLoc.txt." These
files are then used by the minesweeper program.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#define ROWS 9
#define COLS 9

using namespace std;

/**
Function to create a random assortment of mines in a 9x9 grid.
It also writes the grid to a file so it can be used by the
minesweeper program, as well as the rows and column numbers
of all the mines.
*/

int main()  {


    char grid[ROWS][COLS] = {{0}};
    int minesRow[10];
    int minesCol[10];
    srand (time(NULL));

    //fill the arrays with random numbers.
    for (int i = 0; i < 10; i++)  {

        minesRow[i] = (rand() % 9);
        minesCol[i] = (rand() % 9);

        //if two of the random locations are the same, the first digit will
        //be change in the later of the two.
        for (int j = i; j > -1; j--)  {

            if (minesRow[i] == minesRow[j])  {

                    if (minesCol[i] == minesCol[j])  {

                        minesRow[i] = rand() % 9;
                        minesCol[i] = rand() % 9;

                    }//end if

            }//end if

            /*
            else if (minesCol[i] == minesCol[j])  {

                minesCol[i] = rand() % 9;

            }//end else if
            */

        }//end for

    }//end for

    //assign the values to the grid.
    for (int i = 0; i < 9; i++)  {

        for (int j = 0; j < 9; j++)  {

            grid[i][j] = 'X';

        }//end for

    }//end for

    for (int i = 0; i < 10; i++)  {

        grid[minesRow[i]][minesCol[i]] = 'O';

    }//end for

    //write the file which the other program reads.
    int counter = -1;
    fstream file;
    file.open("C:\\Users\\Sam\\Desktop\\275\\MineSweeper\\Mines.txt", ios::out);
    if (file)  {

        for (int i = 0; i < 9; i++)  {

            for (int j = 0; j < 9; j++)  {

                counter += 1;

                if (counter % 9 == 0 && counter != 0)  {

                    file << "\n";

                }//end if

                file << grid[i][j];

            }//end for

        }//end for

    }//end if

    //write the mine rows and columns to a file to help locate the
    //mines in other modules. It was easier to keep track of the mines
    //via their row and column numbers kept as integers, then the locations
    //can be listed with a for loop and is all one data type.
    counter = -1;
    fstream file2;
    file2.open("C:\\Users\\Sam\\Desktop\\275\\MineSweeper\\mineLoc.txt", ios::out);
    if (file2)  {

        for (int i = 0; i < 10; i++)  {

            file2 << minesRow[i] << endl;

        }//end for
        for (int i = 0; i < 10; i++)  {

            file2 << minesCol[i] << endl;

        }//end for

    }//end if

    file.close();
    file2.close();

    return 0;

}//end levelGenerator
