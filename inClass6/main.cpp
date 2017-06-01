/*
Author       : Sam Poff
Project Name : In Class 6
Description  : This program generates an array of values and performs
different functions on them, dependent on what the user wants done.
The array is passed as a pointer.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int checkEntryMenu();
int checkEntrySize();
void display(int size, int* arrptr);
void sortArray(int size, int* arrptr);
void shuffleArray(int size, int *arrptr);
int swapFunc(int &a, int &b);
int findMax(int size, int *arrptr);

int main()  {

    //Flag to keep the program running.
    bool dontQuit = true;

    int size;
    int selection;
    srand (time(NULL));

    //Get size.
    cout << "Please enter the size you would like the array to be." << endl;
    size = checkEntrySize();

    //Initialize Array
    int *arrptr = new int[size];

    //Populate Array
    for (int i = 0; i < size; i++)  {

        arrptr[i] = (rand() % 100 + 1);

    }//end for

    while (dontQuit)  {

        //Menu
        cout << "\nSelect:" << endl;
        cout << "1: Display Array" << endl;
        cout << "2: Sort Array" << endl;
        cout << "3: Shuffle Array" << endl;
        cout << "4: Find Max" << endl;
        cout << "5: Quit" << endl;
        selection = checkEntryMenu();

        if (selection == 1) {

            display(size, arrptr);

        }//end if

        else if (selection == 2)  {

            sortArray(size, arrptr);

        }//end else if

        else if (selection == 3)  {

            shuffleArray(size, arrptr);

        }//end else if

        else if (selection == 4)  {

            int max = findMax(size, arrptr);

            cout << "Max: " << max << endl;

        }//end else if

        else if (selection == 5)  {

            dontQuit = false;

        }//end else if

        else  {

            cout << "YOu dun gooft.";

        }//end else

    }//end while

    //Delete Array
    delete[] arrptr;
    arrptr = NULL;

}//end main

/** Function to check the user's size entry for validity.
* @return size - size of the array.
*/

int checkEntrySize()  {

    int size;
    bool fail = true;

    while (fail)  {

        if (cin >> size)  {

            if (size > 0)  {

                fail = false;

            }//end if

            else  {

                cout << "You must enter an integer value." << endl;

            }//end else

        }//end if

        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "You must enter an integer value." << endl;

        }//end else

    }//end while

    return size;

}//end checkEntry

/** Function to check the user's menu entry for validity.
* @return selection - The menu number the user picked.
*/

int checkEntryMenu()  {

    int selection;

    bool fail = true;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection  <= 5)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 1 and 5." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 5." << endl;

        }//end else

    }//end while

    return selection;

}//end checkEntryAgain

/** Function to display the contents of the array.
*@param size - The size of the array.
*@param arrptr - Pointer to the array.
*/

void display(int size, int* arrptr)  {

    cout << "\n";

    for (int i = 0; i < size; i++)  {

        cout << arrptr[i] << ", ";

        if ((i + 1) % 5 == 0)  {

            cout << "\n";

        }//end if

    }//end for

}//end display

/** Function to sort the array.
*@param size - The size of the array.
*@param arrptr - Pointer to the array.
*/

void sortArray(int size, int* arrptr)  {

    //Sort using the selection sort algorithm
    //from class.
    for (int i = 0; i < size; i++)  {

        int lowest = i;

        for (int j = i + 1; j < size; j++)  {

            if (arrptr[j] < arrptr[lowest])  {

                lowest = j;

            }//end if

        }//end for j

        swapFunc(arrptr[i], arrptr[lowest]);

    }//end for i

}//end sort

/** Function to shuffle the array.
*@param size - The size of the array.
*@param arrptr - Pointer to the array.
*/

void shuffleArray(int size, int* arrptr)  {

    srand(time(NULL));

    //Generate a random 'j', swap with
    //that random 'j'.
    for (int i = size - 1; i > 0; i--)  {

        int j = rand()% (i + 1);

        swapFunc(arrptr[i], arrptr[j]);

    }//end for

}//end shuffleArray

/** Function to find the max of the array.
*@param size - The size of the array.
*@param arrptr - Pointer to the array.
*/

int swapFunc(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;

}

int findMax(int size, int *arrptr)  {

    int max = 0;

    for (int i = 0; i < size; i++)  {

        if (arrptr[i] > max)  {

            max = arrptr[i];

        }//end if

    }//end for

    return max;

}//end findmax
