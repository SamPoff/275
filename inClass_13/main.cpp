#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include "Word.h"
#include "BST.h"

using namespace std;

ostream & operator<< (ostream & out, BST tree)  {
cout << "here";
    out << "Word : " << tree.click.value->getWord() << "\n" << "Freq : " << tree.click.value->getFreq() << endl;

    return out;

}//end ostream

ostream & operator<< (ostream & out, Word myWord)  {
cout << "here";
    out << "Word : " << myWord.word << "\n" << "Freq : " << myWord.freq << endl;

    return out;

}//end ostream

BST readFromFile() {

    BST tree;
    vector<Word> wordVec;
    ifstream file;
    file.open ("words.txt");
    string word;

    while (file >> word)  {

        Word myWord = Word(word);
        tree.add(myWord);
        //cout << myWord << endl;
        cout << tree << endl;
        cout << "here" << endl;

    }//end while

    return tree;

}//end readFromFile

void case1 () {



}//end case1

void case2 () {



}//end case2

int validate()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection <= 3)  {
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

    return selection;

}//end validate

int menu() {

    cout << "MENU" << endl;
    cout << "\n" ;
    cout << "Print : 1" << endl;
    cout << "Search: 2" << endl;
    cout << "Quit  : 3" << endl;

}//end menu

int main() {
//cout << "here";

    BST tree = readFromFile();
    tree.print();
//cout << "here";
    bool keepGoing = true;

    while (keepGoing) {

        menu();
        int selection = validate();

        switch (selection) {
            case 1 : case1();
             break;
            case 2 : case2();
             break;
            case 3 : keepGoing = false;
             break;
        }//end switch

    }//end while

    return 0;

}//end main
