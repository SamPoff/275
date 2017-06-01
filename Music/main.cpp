/*
Poff, Samuel
Project 4
CECS 275
Description: Reads songs from a file and creates a vector of songs.
The user can then choose to add, remove, and print songs.
*/

#include <iostream>
#include <Library.h>
#include <Song.h>
#include <sstream>

using namespace std;

int menu();
int searchMenu();
void makeMainGreatAgain(int selection, Library libObj);
Library removeMenu(int vecSize, Library libObj);

int validateMenu();
int searchMenuValidate();
int validateMakeMainGreatAgain();
int validateRemoveMenu(int size);
Library addSong(Library libObj);

/** Main - Main menu. */
int main()  {

    string fileName = "Songs.txt";
    Library libObj = Library(fileName);

    cout << "SONG MACHINE" << endl;
    cout << "\n";

    bool cont = true;
    while (cont)  {

        int selection = menu();

        if      (selection == 1)  {
            int selection = searchMenu();
            makeMainGreatAgain(selection, libObj);
        }//end if
        else if (selection == 2)  {
            libObj = addSong(libObj);
        }//end else if
        else if (selection == 3)  {
            libObj = removeMenu(libObj.getSize(), libObj);
        }//end else if
        else if (selection == 4)  {
            libObj.printVector();
        }//end else if
        else if (selection == 5)  {
            libObj.writeToFile(fileName);
            libObj.printVector();
            cont = false;
        }//end else if

    }//end while

    return 0;

}//end main

/** Menu which allows the user to select what they
    want to do next.
    @return selection - the user's selection. */
int menu()  {


    cout << "\n";
    cout << "1. Search For A Song" << endl;
    cout << "2. Add a Song" << endl;
    cout << "3. Remove a Song" << endl;
    cout << "4. Display" << endl;
    cout << "5. Quit" << endl;

    int selection = validateMenu();
    return selection;

}//end menu

/** Search Menu - Asks the user how they would like to search the songs.
@return selection - user's selection. */
int searchMenu()  {

    std::cout << "\nSearch By:" << std::endl;
    std::cout << "1: Title" << std::endl;
    std::cout << "2: Artist" << std::endl;
    std::cout << "3: Album" << std::endl;
    std::cout << "4: Decade" << std::endl;

    int selection = searchMenuValidate();

    return selection;

}//end searchMenu

/** Extention of Search Menu - Asks for title name / artist name, etc.
@param selection - the user's selection.
@param libObj - Library object. */
void makeMainGreatAgain(int selection, Library libObj)  {

    if      (selection == 1)  {
        string title;
        cout << "\nWhat title would you like to look for?" << endl;
        cin.ignore();
        getline(cin, title);
        cin.clear();
        libObj.searchTitle(title, libObj);
    }//end if
    else if (selection == 2)  {
        string artist;
        cout << "\nWhat artist would you like to look for?" << endl;
        cin.ignore();
        getline(cin, artist);
        cin.clear();
        libObj.searchArtist(artist, libObj);
    }//end else if
    else if (selection == 3)  {
        string album;
        cout << "\nWhat album would you like to look for?" << endl;
        cin.ignore();
        getline(cin, album);
        cin.clear();
        libObj.searchAlbum(album, libObj);
    }//end else if
    else if (selection == 4)  {
        int decade;
        cout << "\nWhat decade would you like to look for?" << endl;
        decade = validateMakeMainGreatAgain();
        libObj.searchYear(decade, libObj);
    }//end else if
    else {
        /*     \,,/(^_^)\,,/     */
    }//end else

}//end makeMainGreatAgain

/** Remove Menu - Menu for removing songs.
@param vecSize - size of the song vector.
@param libObj - Library object.
@return libObj - Library object. */
Library removeMenu(int vecSize, Library libObj)  {

    int menuSize = 2;

    cout << "\nRemove Song By: " << endl;
    cout << "1: Index" << endl;
    cout << "2: Title" << endl;

    int selection = validateRemoveMenu(menuSize);

    if (selection == 1)  {
        cout << "\n";
        libObj.printVectorNotSorted();
        cout << "\nPick a number to remove:\n " << endl;
        int selection = validateRemoveMenu(vecSize) - 1;
        libObj.removeSongLib(selection);
    }//end if
    else if (selection == 2)  {
        cout << "\n";
        libObj.printVectorNotSorted();
        cout << "\nPlease type the title of the song you would like to delete.\n" << endl;
        string selection;
        cin.ignore();
        getline(cin, selection);
        cin.clear();
        libObj.removeByTitle(selection);
    }//end else if
    else  {
        /*    (-(-_(-_-)_-)-)   no  */
    }//end else

    return libObj;

}//end removeMenu

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validateMenu()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection <= 5)  {
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

}//end validate2

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int searchMenuValidate()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (std::cin >> selection)  {

            if (selection >= 1 && selection <= 4)  {
                fail = false;
            }//end if
            else  {
                std::cout << "Invalid entry, please enter a number between 1 and 4." << std::endl;
            }//end else

        }//end if

        else  {
            std::cin.clear();
            std::string invalid;
            std::cin >> invalid;
            std::cout << "Invalid entry, please enter a number between 1 and 4." << std::endl;
        }//end else

    }//end while

    return selection;

}//end validate2

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validateMakeMainGreatAgain()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            switch(selection)  {
                case 00: fail = false; break;
                case 10: fail = false; break;
                case 20: fail = false; break;
                case 30: fail = false; break;
                case 40: fail = false; break;
                case 50: fail = false; break;
                case 60: fail = false; break;
                case 70: fail = false; break;
                case 80: fail = false; break;
                case 90: fail = false; break;
                default:
                    cout << "Invalid entry, please enter a two digit number ending in zero." << endl;
            }

        }//end if

        else  {
            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a two digit number ending in zero." << endl;
        }//end else

    }//end while

    return selection;

}//end validateMakeMainGreatAgain

/** Validates the user's menu selection.
    @return selection - the user's validated selection. */
int validateRemoveMenu(int menuSize)  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (std::cin >> selection)  {

            if (selection >= 1 && selection <= menuSize)  {
                fail = false;
            }//end if
            else  {
                std::cout << "Invalid entry, please enter a number between 1 and " << menuSize << "." << std::endl;
            }//end else

        }//end if

        else  {
            std::cin.clear();
            std::string invalid;
            std::cin >> invalid;
            std::cout << "Invalid entry, please enter a number between 1 and " << menuSize << "." << std::endl;
        }//end else

    }//end while

    return selection;

}//end validateRemoveMenu

/** Add Song - Adds song to song vector.
@param libObj - Library object.
@return libObj - Library object. */
Library addSong(Library libObj)  {

    Song newSong;

    cin >> newSong;

    libObj.addSongLib(newSong);

    cout << "\n";

    return libObj;

}//end addSong


