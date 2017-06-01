#include <LinkedList.h>
#include <Person.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
/*
istream &operator>>( istream  & input, Person p ) {
    input >> p.lastName >> p.firstName >> p.phoneNumber >> p.address >> p.city >> p.zip >> p.state;
    return input;
}//end operator>>*/

ostream & operator<< (ostream & out, Person & p) {
    out << p.retLN() << ","
        << p.retFN() << ","
        << p.retPN() << ","
        << p.retAD() << ","
        << p.retCI() << ","
        << p.retZI() << ","
        << p.retST()      ;
        return out;
}//end operator<<

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validate()  {

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

}//end validate

/** Displays the main menu. */
void mainMenu() {
    cout << "Rolodex Menu:" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search for Contact" << endl;
    cout << "3. Modify Contact" << endl;
    cout << "4. Display Contacts" << endl;
    cout << "5. Quit" << endl;
}//end mainMenu

/**  */
void fillList(LinkedList & list) {

    string input, fn, ln, ad, ci, st, pn, zi;
    ifstream file ("addresses.txt");

    while (getline(file, input))  {

        stringstream linestream(input);

        getline(linestream, fn , ',');

        getline(linestream, ln , ',');

        getline(linestream, pn , ',');

        getline(linestream, ad , ',');

        getline(linestream, ci , ',');

        getline(linestream, zi , ',');

        getline(linestream, st , ',');

        Person p = Person(fn, ln, pn, ad, ci, zi, st);

        list.add(p);

    }//end while

}//end generateList

int main() {

    LinkedList list;
    fillList(list);
    mainMenu();
    list.print();

}//end main
