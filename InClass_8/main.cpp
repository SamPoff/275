#include <iostream>
#include "Fraction.h"
#include "Fraction.cpp"

using namespace std;

int validateMenu();
int menu();

/** Overloaded output operator; enables a formatted output for
    Fraction objects.
    @return out - the io stream with the desired output. */
std::ostream & operator<< (std::ostream & out, Fraction   myFrac)  {

    out << "\n" << myFrac.numerator << "/" << myFrac.denominator << "\n";
    return out;

}//end ostream

/** Overloaded input operator; allows user inputs to be assigned
    to specific class traits in one call.
    @return in - the input stream with the user's values. */
std::istream & operator>> (std::istream & in,  Fraction & myFrac)  {

    cout << "Please enter a numerator" << endl;
    bool fail = true;
    while (fail)  {
        if (in >> myFrac.numerator)  {
            fail = false;
        }//end if
        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter an integer" << endl;
        }//end else
    }//end while

    cout << "Please enter a denominator" << endl;
    fail = true;
    while (fail)  {
        if (in >> myFrac.denominator)  {
            fail = false;
        }//end if
        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter an integer" << endl;
        }//end else
    }//end while

    if (myFrac.denominator == 0)  {
        myFrac.denominator = 1;
    }//end if

    cout << myFrac << endl;

    return in;

}//end instream

/** Main; calls the menu and directs the program
    based on the user's selections. */
int main()  {

    bool dontQuit = true;

    Fraction frac1 = Fraction();
    Fraction frac2 = Fraction();

    cin >> frac1;
    cin >> frac2;

    while (dontQuit)  {

        int selection = menu();

        if (selection == 1)  {
            Fraction added = frac1 + frac2;
            cout << "\n" << added << endl;
        }//end if
        else if (selection == 2)  {
            Fraction sub = frac1 - frac2;
            cout << "\n" << sub << endl;
        }//end else if
        else if (selection == 3)  {
            Fraction mult = frac1 * frac2;
            cout << "\n" << mult << endl;
        }//end else if
        else if (selection == 4)  {
            Fraction div = frac1 / frac2;
            cout << "\n" << div << endl;
        }//end else if
        else if (selection == 5)  {
            cin >> frac1;
            cin >> frac2;
        }//end else if
        else if (selection == 6)  {
            dontQuit = false;
        }//end else if

    }//end while

    return 0;

}//end main

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validateMenu()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection <= 6)  {
                fail = false;
            }//end if
            else  {
                cout << "Invalid entry, please enter a number between 1 and 6." << endl;
            }//end else

        }//end if

        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and 6." << endl;
        }//end else

    }//end while

    return selection;

}//end validate2

/** Menu which allows the user to select what they
    want to do next.
    @return selection - the user's selection. */
int menu()  {

    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Enter Two New Fractions" << endl;
    cout << "6. Quit" << endl;

    int selection = validateMenu();
    return selection;

}//end menu


