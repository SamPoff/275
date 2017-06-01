/**
Project    : Minesweeper
Author     : Sam Poff, CECS 275, T/R 1100
Description: This program allows the user to fill out a ten part
integer array, then performs various tasks as instructed by the user.
*/

#include <iostream>
#define size 10

using namespace std;

void populateArray(int arrayOfTen[]);
void displayNumbers(int arrayOfTen[]);
void reverseNumbers(int arrayOfTen[]);
int findValue(int arrayOfTen[]);
void insertValue(int arrayOfTen[]);
int maxValue(int arrayOfTen[]);
int computeSum(int arrayOfTen[]);
int computeAverage(int arrayOfTen[]);

/**
This is the main function, it controls which task the program should perform
based on user selection.
@param arrayOfTen - the array which the user populated.
@param sum - the sum of the numbers the user entered.
@param size - size of the array.
*/

int main()  {

    /**
    This is the main function, it controls which task the program should perform
    based on user selection.
    @param arrayOfTen - the array which the user populated.
    @param sum - the sum of the numbers the user entered.
    @param size - size of the array.
    */

    // Welcome user.
    cout << "Welcome to the array thing." << endl;
    cout << "\n";

    //bool fail = true;
	bool flag = true;

    // Declare array.
    int arrayOfTen[size];
    int selection;
    int found = 0;
    int biggest = 0;

    // Call populate array function.
    populateArray(arrayOfTen);
    displayNumbers(arrayOfTen);

	while (flag)  {

        bool fail = true;

		while (fail)  {

            // Display menu and prompt user.
			cout << "To display numbers,___________________select 1." << endl;
			cout << "To display the numbers reversed,______select 2." << endl;
			cout << "To display the sum,___________________select 3." << endl;
			cout << "To display the average,_______________select 4." << endl;
			cout << "To display the maximum,_______________select 5." << endl;
			cout << "To search for a value,________________select 6." << endl;
			cout << "To insert a new value,________________select 7." << endl;
			cout << "To quit,______________________________select 8." << endl;

			if (cin >> selection)  {

                if (selection < 9 && selection > 0)  {

                    if (selection == 1)  {

                        displayNumbers(arrayOfTen);

                    }//end else if
                    else if (selection == 2)  {

                        reverseNumbers(arrayOfTen);

                    }//end else if
                    else if (selection == 7)  {

                        insertValue(arrayOfTen);
                        displayNumbers(arrayOfTen);

                    }//end else if
                    else if (selection == 6)  {

                        found = findValue(arrayOfTen);
                        if (found == -1)  {

                            cout << "That number was not found. Try searching for another." << endl;

                        }//
                        else  {

                            cout << "\nThe location of the number you are looking for is spot " << found << "\n" << endl;

                        }//end else

                    }//end else if
                    else if (selection == 3)  {

                        int sum = computeSum(arrayOfTen);
                        cout << "\nThe sum is: " << sum << "\n" << endl;

                    }//end else if
                    else if (selection == 4)  {

                        cout << "\nThe average is " << computeSum(arrayOfTen) / size << "\n" << endl;

                    }//end else if
                    else if (selection == 5)  {

                        biggest = maxValue(arrayOfTen);
                        cout << "\nThe biggest value is " << biggest << "\n" << endl;

                    }//end else if
                    else if (selection == 8)  {

                        flag = false;
                        break;

                    }//end else if
                    else {

                        // Not necessary if input has been validated.

                    }//end else

                }//end if

			}//end if
			else  {

				cin.clear();
				string invalid;
				cin >> invalid;
				cout << "Invalid Input" << endl;

			}//end else

		}//end while

	}//end while

	return 0;

}//end main

/**
Function which takes in user input and populates the array.
@param size - size of the array.
@param fail - boolean which controls input validation.
@param arrayOfTen - the array.
@param invalid - dummy string to dump bad input.
*/


void populateArray(int arrayOfTen[])  {

    cout << "Please enter ten numbers to populate the array." << endl;
    cout << "Press 'Enter' after each entry." << endl;

    for (int i = 0; i < size; i++)  {

        bool fail = true;

        while (fail)  {

            if (cin >> arrayOfTen[i])  {

                fail = false;

            }//end if
            else  {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid Input" << endl;

            }//end else

        }//end while

    }//end for

}//end populateArray

/**
Function which will display the provided array.
@param arrayOfTen - the array which the user populated.
*/

void displayNumbers(int arrayOfTen[])  {

    cout << "\nThe numbers you picked are:" << endl;

    for (int i = 0; i < size; i++)  {

        if (i == (size - 1))  {

            cout << arrayOfTen[i] << "." << endl;

        } else  {//end if

            cout << arrayOfTen[i] << ", ";

        }//end else

    }//end for

    cout << "\n";

}//end displayNumbers

/**
Function which displays the numbers reversed.
@param arrayOfTen - the array which the user populated.
*/

void reverseNumbers(int arrayOfTen[])  {

    int dummyArray[size];

    for (int i = 0; i < size; i++)  {

        dummyArray[i] = arrayOfTen[9 - i];

    }//end for

    cout << "\nReversed:" << endl;

    for (int i = 0; i < size; i++)  {

        if (i < size - 1)  {

            cout << dummyArray[i] << ", ";

        }//end if
        else  {

            cout << dummyArray[i] << " ";

        }//end else

    }//end for

    cout << "\n";
    cout << "\n";

}//end arrayOfTen

/**
This function allows the user to insert a new value into the array.
@param arrayOfTen - the array which the user populated.
*/

void insertValue(int arrayOfTen[])  {

        int location;
        int replacement;
        bool fail1 = true;
        bool fail2 = true;

        while (fail1)  {

            cout << "\nPlease enter the location of the character you would like to replace." << endl;

            if (cin >> location)  {

                if (location < 11 && location  > 0)  {

                    fail1 = false;

                }//end if
                else  {

                    cout << "Invalid entry, please enter a number between 1 and 10." << endl;

                }//end else

            }//end if
            else  {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid Input" << endl;

            }//end else

        }//end while

        while (fail2)  {

            cout << "Please enter the value you would like to replace it with." << endl;

            if (cin >> replacement)  {

                fail2 = false;

            }//end if
            else  {

                cin.clear();
                string invalid;
                cin >> invalid;
                cout << "Invalid Input" << endl;

            }//end else

        }//end while

        int dummyArray[size];

        for (int i = 0; i < size; i++)  {

            dummyArray[i] = arrayOfTen[i];

        }//end for

        dummyArray[location - 1] = replacement;

        for (int i = 0; i < size; i++)  {

            arrayOfTen[i] = dummyArray[i];

        }//end for

}//end insertValue

/**
Allows the user to search for a value in the array.
@param arrayOfTen - the array which the user populated.
@return flagThing - the location of the value the user wants to find.
*/

int findValue(int arrayOfTen[])  {

    int flagThing = 0;
    bool fail1 = true;
    int value;
    int didntFind = 0;

    while (fail1)  {

        cout << "\nPlease enter the value you would like to look for." << endl;

        if (cin >> value)  {

            for (int i = 0; i < size; i++)  {

                if (arrayOfTen[i] == value)  {

                    //cout << "\nThe location of the number you are looking for is spot " << value << "\n" << endl;
                    flagThing = value;
                    fail1 = false;

                }//end if
                else  {

                    didntFind += 1;

                }//end else

            }//end for

            if (didntFind == 10)  {

                cout << "That number was not found. Try searching for another." << endl;
                flagThing = -1;

            }//end if

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "\nInvalid entry, please enter a number." << endl;

        }//end else

    }//end while

    return flagThing;

}//end findValue

/**
Returns the sum of all the values in the array.
@param arrayOfTen - the array the user filled out.
@return sum - the sum of the array's values.
*/

int computeSum(int arrayOfTen[])  {

    int sum1 = 0;

    for (int i = 0; i < size; i++)  {

        sum1 += arrayOfTen[i];

    }//end for

    return sum1;

}//end computeSum

/**
Returns the largest of all the values in the array.
@param arrayOfTen - the array the user filled out.
@return biggest - The sum of the values in the array.
*/

int maxValue(int arrayOfTen[])  {

    int biggest = 0;

    for (int i = 0; i < size; i++)  {

        if (arrayOfTen[i] > biggest)  {

            biggest = arrayOfTen[i];

        }//end if

    }//end for

    return biggest;

}//end maxValue

