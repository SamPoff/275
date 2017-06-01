#include <iostream>
#include <fstream>

#define f1s 25  // File One Size
#define f2s 65  // File Two Size
#define f3s 101 // File Three Size

using namespace std;

/** Create a new array with a capacity of 10
*   @param size - size of array.
*   @return ptr - pointer to the array. */
int * initializeArray(int size)  {

    int * ptr;
    int sizer = size;
    ptr = new int[sizer]; // Size == 10

    for (int i = 0; i < sizer; i++)  {

        ptr[i] = 0;

    }//end for

    return ptr;

}//end initializeArray

/** Display array
*   @param ptr - pointer to array.
*   @param size - size of the array. */
void displayArray(int * ptr, int size, int lastIndex[0])  {

    for (int i = 0; i < lastIndex[0] + 1; i++)  {
        if (i % 5 == 0)  {
            cout << "\n";
        }//end if
        cout << ptr[i] << ", ";
    }//end for

    cout << "\n";

}//end displayArray

/** Increases the capacity of the array by creating
*   a new array with the correct amount of space.
*   @param ptr - pointer to the array.
*   @param size - size of the array.
*   @return ptr2 - new pointer to resized array. */
int * increaseCapacity(int * ptr, int size)  {

    int * ptr2 = initializeArray(size + 10);
    for (int i = 0; i < (size + 10); i++)  {
        if (i < size)  {
            ptr2[i] = ptr[i];
        }//end if
        else  {
            ptr2[i] = 0;
        }//end else
    }//end for

    return ptr2;

}//end increaseCapacity

/** Add a new value to the end of the array, if
*   it has already reached capacity then call
*   'increaseCapacity()'.
*   @param ptr - pointer to the array.
*   @param size - size of the array.
*   @param selection - number to be added.
*   @return ptr - pointer to the array. */
int * addItem(int * ptr, int size, int selection, int lastIndex[0])  {

    if (lastIndex[0] == size - 1)  {
        ptr = increaseCapacity(ptr, size);
        lastIndex[0] += 1;
        size += 10;

        ptr[lastIndex[0]] = selection;

        return ptr;

    }//end if

    // Empty spot found.
    lastIndex[0] += 1;
    ptr[lastIndex[0]] = selection;

    return ptr;

}//end addItem

/** Swaps the values of two variables
*   @param ptr - pointer to the array.
*   @param val1 - first value to be swapped.
*   @param val2 - second value to be swapped.
*   @return ptr - pointer to the array. */
int * swapper(int * ptr, int val1, int val2)  {

    int temp1 = ptr[val1];
    ptr[val1] = ptr[val2];
    ptr[val2] = temp1;

    return ptr;

}//end swapper

/** Inserts one value at a given index
*   @param ptr - pointer to the array.
*   @param index - index to insert a number to.
*   @param newVal - value to be inserted.
*   @param size - size of the array.
*   @param checkSize[] - lets main know if size needs to change.
*   @return ptr - pointer to the array. */
int * inserter(int * ptr, int index, int newVal, int size, int lastIndex[0])  {

    // Increase capacity by ten if needed.
    if (lastIndex[0] == size - 1)  {
        ptr = increaseCapacity(ptr, size);
        size += 10;
        lastIndex[0] += 1;
    }//end if

    // Change values.
    for (int i = size; i >= index; i--)  {
        ptr[i + 1] = ptr[i];
    }//end for

    ptr[index] = newVal;

    return ptr;

}//end inserter

/** Removes one value at a given index
*   @param ptr - pointer to the array.
*   @param index - index to insert a number to.
*   @param size - size of the array.
*   @return ptr - pointer to the array. */
int * remover(int * ptr, int index, int lastIndex[0])  {

    for (int i = index; i < lastIndex[0] + 1; i++)  {
        if (i < lastIndex[0] ) {ptr[i] = ptr[i + 1];}
        else {ptr[i] = 0;}
    }//end for

    return ptr;

}//end remover

/** Replaces one value at a given index
*   @param ptr - pointer to the array.
*   @param index - index to insert a number to.
*   @param newVal - value to be inserted.
*   @return ptr - pointer to the array. */
int * replacer(int * ptr, int index, int newVal)  {

    ptr[index] = newVal;

    return ptr;

}//end replacer

/** Returns the index of a number the user is
*   searching for. Return '-1' if it is not found.
*   @param ptr - pointer to the array.
*   @param value - value to be found.
*   @param size - size of the array.
*   @return ptr - pointer to the array. */
int indexOf(int * ptr, int value, int size)  {

    int index[1] = {0};
    index[0] = -1;

    for (int i = 0; i < size; i++)  {
        if (ptr[i] == value)  {
            index[0] = i;
        }//end if
        else  {/*No big deal*/}
    }//end for

    return index[0];

}//end indexOf

/** Returns a boolean value depending on if it could
*   find the value the user searched for.
*   @param ptr - pointer to the array.
*   @param value - value to be checked.
*   @param size - size of the array.
*   @return flag[] - boolean which lets the user know if found. */
bool exist(int * ptr, int value, int size)  {

    bool flag[1] = {0};

    for (int i = 0; i < size; i++)  {
        if (ptr[i] == value)  {
            flag[0] = true;
            break;
        }//end if
        else  {flag[0] = false;}
    }//end for

    return flag[0];

}//end exist

/** Sorts the array using selection sorting.
*   @param ptr - pointer to the array.
*   @param size - size of the array. */
void sorter(int * ptr, int lastIndex[0])  {

    //Sort the vector.
    for (int i = 0; i < lastIndex[0] + 1; i++)  {

        int lowest = i;

        for (int j = (i + 1); j < lastIndex[0] + 1; j++)  {

            if (ptr[lowest] > ptr[j])  {

                lowest = j;

            }//end if

        }//end for

        int swapVar = ptr[i];
        ptr[i] = ptr[lowest];
        ptr[lowest] = swapVar;

    }//end for

}//end sorter

/** Input validation (1 - 11). Used for menu and index.
*   @return selection - user's selection. */
int validate_1_11()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection  <= 11)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 1 and 11." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 11." << endl;

        }//end else

    }//end while

    return selection;

}//end validate_1_11

/** Input validation (1 - 10). Used for menu and index.
*   @return selection - user's selection. */
int validate_1_10()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection  <= 10)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 1 and 10." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 10." << endl;

        }//end else

    }//end while

    return selection;

}//end validate_1_10

/** Input validation (int) used for getting values.
*   @return selection - user's selection. */
int validate_int()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            fail = false;

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter an integer." << endl;

        }//end else

    }//end while

    return selection;

}//end validate_int

/** Input validation (1 - 3) used for getting values.
*   @return selection - user's selection. */
int validate_1_3()  {

    bool fail = true;
    int selection;

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
            cout << "Invalid entry, please enter an integer; 1, 2, or 3." << endl;

        }//end else

    }//end while

    return selection;

}//end validate_int

/** Input validation (size) used for getting index values.
*   @return selection - user's selection. */
int validate_size(int size)  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 0 && selection  < size)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 0 and " << size - 1 << "." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 0 and " << size - 1 << "." << endl;

        }//end else

    }//end while

    return selection;

}//end validate_int

/** Reads values from a file
*   @param ptr - pointer to the array.
*   @param fileNumber - number of selected file.
*   @param size - the size of the array.
*   @return ptr - pointer to the array. */
int * readFile(int *ptr, int fileNumber, int size)  {

    fstream file;

    // Open the correct file.
    // Get a new size based on file choice.
    // Make new array of the correct size.
    if (fileNumber == 1)  {
        file.open("file1.txt", ios::in);
        ptr = initializeArray(size);
    }//end if
    else if (fileNumber == 2)  {
        file.open("file2.txt", ios::in);
        ptr = initializeArray(size);
    }//end else if
    else if (fileNumber == 3)  {
        file.open("file3.txt", ios::in);
        ptr = initializeArray(size);
    }//end else if
    else  {
        // Doubtful.
    }//end else

    // Fill new array up.
    for (int i = 0; i < size; i++)  {
        file >> ptr[i];
    }//end for

    return ptr;

}//end readFile

/** The main menu
*   @return selection - user's menu selection */
int menu()  {

    cout << "\nMENU: " << endl;
    cout << "1.  Add from file " << endl;
    cout << "2.  Display contents " << endl;
    cout << "3.  Add new value at end " << endl;
    cout << "4.  Insert new value " << endl;
    cout << "5.  Sort values " << endl;
    cout << "6.  Swap values " << endl;
    cout << "7.  Remove value " << endl;
    cout << "8.  Replace value " << endl;
    cout << "9.  Find value " << endl;
    cout << "10. Check if value exists " << endl;
    cout << "11. Quit " << endl;

    int selection = validate_1_11();

}//end menu

/** Main - main. */
int main()  {

    int size = 10;
    int *ptr = initializeArray(size);
    bool dontStopBeliebing = true;
    int lastIndex[1] = {0};
    lastIndex[0] = 9;

    while (dontStopBeliebing)  {

        int selection = menu();

        // Add from file
        if (selection == 1)  {
            //Figure out which file to read.
            cout << "\nWould you like to use file 1, 2, or 3?" << endl;
            int selection = validate_1_3();
            if      (selection == 1)  {
                size = f1s;
                lastIndex[0] += f1s - 1; }
            else if (selection == 2) {
                size = f2s;
                lastIndex[0] += f2s - 1; }
            else if (selection == 3) {
                size = f3s;
                lastIndex[0] += f3s - 1; }
            else {/* No way Jose */}
            ptr = readFile(ptr, selection, size);
        }//end if

        // Display contents
        else if (selection == 2)  {
            displayArray(ptr, size, lastIndex);
        }//end else if

        // Add new value to end.
        else if (selection == 3)  {
            cout << "\nWhat value would you like to add?" << endl;
            int selection = validate_int();
            ptr = addItem(ptr, size, selection, lastIndex);
            if (lastIndex[0] == size)  {
                size += 10;
            }//end if
        }//end else if

        // Insert new value
        else if (selection == 4)  {
            cout << "\nWhat value would you like to add?" << endl;
            int value = validate_int();
            cout << "\nWhat index would you like it placed in?" << endl;
            int index = validate_size(size);
            int checkSize[1] = {0};
            checkSize[0] = -1;
            ptr = inserter(ptr, index, value, size, lastIndex);
            if (checkSize[0] == 1) {size += 10; lastIndex[0] += 1;}
        }//end else if

        // Sort values.
        else if (selection == 5)  {
            sorter(ptr, lastIndex);
        }//end else if

        // Swap values
        else if (selection == 6)  {
            cout << "What is the index of the first value?" << endl;
            int selection = validate_size(lastIndex[0] + 1);
            cout << "What is the index of the second value?" << endl;
            int selection2 = validate_size(lastIndex[0] + 1);
            ptr = swapper(ptr, selection, selection2);
        }//end else if

        // Remove value.
        else if (selection == 7)  {
            cout << "What is the index of the value you would like to remove?" << endl;
            int selection = validate_size(size);
            ptr = remover(ptr, selection, lastIndex);
            lastIndex[0] -= 1;
            size -= 1;
        }//end else if

        // Replace value.
        else if (selection == 8)  {
            cout << "\nWhat value would you like to add?" << endl;
            int value = validate_int();
            cout << "\nWhat is the index you would like to replace?" << endl;
            int index = validate_size(size);
            ptr = replacer(ptr, index, value);
        }//end else if

        // Find value.
        else if (selection == 9)  {
            cout << "\nWhat is the value you would like to search for?" << endl;
            int selection = validate_int();
            int result = indexOf(ptr, selection, size);
            if (result == -1)  {
                cout << "\nThat value was not found." << endl;
            }//end if
            else  {
                cout << "\nThe values index is " << result << "." << endl;
            }//end else
        }//end else if

        // Check if value exists.
        else if (selection == 10)  {
            cout << "\nWhat is the value you would like to search for?" << endl;
            int selection = validate_int();
            bool weDidIt = exist(ptr, selection, size);
            if (weDidIt) {
                cout << "\nTrue" << endl;
            }// end if
            else {cout << "\nFalse" << endl;}
        }//end else if

        // Quit
        else if (selection == 11)  {
            delete[] ptr;
            ptr = NULL;
            dontStopBeliebing = false;//o no
        }//end else if

        else  {
            // Loop
        }//end else

    }//end while

}//end main

