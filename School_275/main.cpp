/*
 * Samuel Poff
 *
 * 23 Aug 2016
 *
 * A guessing game where the user inputs a number between 1 and 100 and the program lets them know how they guessed.
*/


#include <iostream>
#include <stdlib.h>
using namespace std;
int main()  {

    int userInput;

	// Generate a random number in [1,100]
	int randNum = rand() % 100 + 1;
	cout << randNum;

    // Prompt the user to input a value
    cout << "Please enter a number between 1 and 100." << endl;
    cin >> userInput;

    // Input validation
    while (userInput > 100 || userInput < 1)  {

        cout << "Your number must be between 1 and 100." << endl;
        cout << "Please enter a new number." << endl;
        cin.clear();
        cin >> userInput;

    }//end while

    return 0;

}//end main




