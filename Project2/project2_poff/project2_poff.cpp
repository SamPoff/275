/*
Author       : Sam Poff
Project Name : Project 2
Description  : This program is able to read in text files
populated with '#' and 'o' symbols and it will count how many
'o's are in a given area.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define rows 10
#define cols 10

using namespace std;

void readInGridFile(char grid[rows][cols], string gridFile); // Read in 8x8 grid and save it to
//                                                              the middle of a 10x10 grid.
void displayGrid(char grid[rows][cols]); // Display 8x8 grid.
void traverse(char grid[rows][cols]); // Traverse the grid 1x1, if you find an 'o' which
//                                       hasn't been counted before call countArea().
int countArea(int row, int col, char sacrifice[rows][cols], int counter); // Counts how many 'o's
//                                                                        are in an area recursively.

/**
This is the program's main. It calls all the other functions in the
program.
*/

int main()  {

    char grid[rows][cols] = {
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                            };

    int selection;

    bool dontQuit = true;

    string gridFile;

    //while loop keeps the program running until the user wants it to quit.
    while (dontQuit)  {

        bool fail = true;

        cout << "\nGrid Area Counter" << endl;
        cout << "Enter Grid #: ";

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

        if (selection == 1)  {

            gridFile = "grid1.txt";
            readInGridFile(grid, gridFile);
            displayGrid(grid);
            traverse(grid);

        }//end if
        else if (selection == 2)  {

            gridFile = "grid2.txt";
            readInGridFile(grid, gridFile);
            displayGrid(grid);
            traverse(grid);

        }//end else if
        else if (selection == 3)  {

            gridFile = "grid3.txt";
            readInGridFile(grid, gridFile);
            displayGrid(grid);
            traverse(grid);

        }//end else if
        else  {

            cout << "\nThat feel when your program is broken.\n" << endl;

        }//end else

    }//end while

}//end main

/**
This function reads in the grid from a file and places it in the center
8x8 of a 10x10 grid array.
@param grid - The 10x10 grid to contain the '#' and 'o' symbols which will be
saved from the file.
@param gridFile - A string holding the name of the grid file.
*/

void readInGridFile(char grid[rows][cols], string gridFile)  {

    fstream file;
    string input;
    file.open(gridFile.c_str(), ios::in);

    //test to see if the file exists
    if (file)  {

        for (int i = 0; i < 8; i++)  {

            for (int j = 0; j < 8; j++)  {

                file >> grid[i + 1][j + 1];

            }//end for

        }//end for

        file.close();

    }//end if

}//end readInGridFile

/**
This function displays the contents of the grid, removing
the extra two rows and columns.
@param grid - The 10x10 grid containing the '#' and 'o' symbols
saved from the file.
*/

void displayGrid(char grid[rows][cols])  {

    for (int i = 0; i < rows; i++)  {

        for (int j = 0; j < cols; j++)  {

            if ((j + 1) % 10 == 0)  {

                cout << "\n";

            }//end if
            else  {

                if ((i > 0) && (i < rows - 1) && (j > 0) && (j < cols - 1))  {

                    cout << grid[i][j];

                }//end if

            }//end else

        }//end for

    }//end for

}//end displayGrid

/**
The purpose of this function is to step throught the grid and search for
'o's. If it finds one it is supposed to call the function which counts the
'o's area (countArea).
@param grid - The 10x10 grid containing the '#' and 'o' symbols
saved from the file.
*/

void traverse(char grid[rows][cols])  {

    char sacrifice[rows][cols] = {{0}};
    int counter1 = 0;
    int counter2 = 0;

    for (int i = 0; i < rows; i++)  {

        for (int j = 0; j < cols; j++)  {

            sacrifice[i][j] = grid[i][j];

        }//end for

    }//end for

    for (int i = 0; i < rows; i++)  {

        for (int j = 0; j < cols; j++)  {

            if (grid[i][j] == 'o' && sacrifice[i][j] != 'X')  {

                if (i == 1 && j == 1)  {

                    counter1 += 1;

                }//end if
                if (i == 1 && j == 8)  {

                    counter1 += 1;

                }//end if
                if (i == 8 && j == 1)  {

                    counter1 += 1;

                }//end if
                if (i == 8 && j == 8)  {

                    counter1 += 1;

                }//end if

                counter1 = countArea(i, j, sacrifice, counter1);
                cout << "Area " << counter2 + 1 << " = " << counter1 << endl;
                counter2 += 1;
                counter1 = 0;

            }//end if

        }//end for

    }//end for

}//end traverse

/**
The purpose of this function is to recursively count the number of 'o's
in the area of the passed spot.
@param grid - The 10x10 grid containing the '#' and 'o' symbols
saved from the file.
*/

int countArea(int row, int col, char sacrifice[rows][cols], int counter)  {

    if ((row >= 1 && row <= 9) && (col >= 1 && col <= 9))  {

        if(sacrifice[row + 1][col] == 'o')  {
            sacrifice[row + 1][col] = 'X';
            counter = 1 + countArea((row + 1), col, sacrifice, counter);
        }//end if
        if(sacrifice[row - 1][col] == 'o')  {
            sacrifice[row - 1][col] = 'X';
            counter = 1 + countArea((row - 1), col, sacrifice, counter);
        }//end if
        if(sacrifice[row][col + 1] == 'o')  {
            sacrifice[row][col + 1] = 'X';
            counter = 1 + countArea(row, (col + 1), sacrifice, counter);
        }//end if
        if(sacrifice[row][col - 1] == 'o')  {
            sacrifice[row][col - 1] = 'X';
            counter = 1 + countArea(row, (col - 1), sacrifice, counter);
        }//end if

    }//end while

    return counter;

}//end countArea
