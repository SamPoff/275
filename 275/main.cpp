/*
 * Author:      Samuel Poff
 *
 * Date:        23 Aug 2016
 *
 * Description: A guessing game where the user inputs a number between 1 and 100 and the program lets them know how they guessed.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    // Instantiate variables.
    int userInput;
    int count = 1;
    bool flag = true;
    #define HIGH_NUM 100
    #define LOW_NUM 1

	// Generate a random number in [1,100]
	srand(time(NULL));
	int randNum = rand() % HIGH_NUM + LOW_NUM;
	cout << randNum << endl;

    while (flag)  {

        cout << "Please enter a number between 1 and 100." << endl;
        cin >> userInput;

        // Input validation
        if (cin.fail())  {

            cout << "You must enter an integer, between 1 and 100." << endl;
            cin.clear();
            cin.get();

        }//end if

        else if (userInput > 100 || userInput < 1)  {

            cout << "You must enter an integer, between 1 and 100." << endl;
            cin.clear();
            cin.get();

        }//end if

        else  {


                if (userInput > randNum)  {

                cout << "Your guess was too high." << endl;
                count += 1;

                }//end if

                else if (userInput < randNum)  {
                cout << "Your guess was too low." << endl;
                count += 1;

                }//end if

                else if (userInput == randNum)  {

                cout << "You guessed correctly!" << endl;
                cout << "It took you " << count << " guesses (not including invalid attempts)." << endl;
                flag = false;


            }//end if

        }//end else

    }//end while

    return 0;

}//end main

