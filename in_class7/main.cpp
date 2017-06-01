/*
Author       : Sam Poff
Project Name : In Class 6
Description  : This program generates an array of objects and performs
different functions to them, dependent on what the user wants done.
The objects in the array represent bank accounts, so the functions
mostly have to do with moving around sums of money.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "BankAccount.h"

using namespace std;

int menu1(bool &com);
int menu2();
int validate(int menuSize);
int validate2();
int validate3();
double accrue(int accountSelect, double interest, int years, BankAccount account[]);

/** The main menu, contains conditional logic dependent on menu returns. */

int main()  {

    bool com = true;
    double balance = 0;
    int accountSelect;

    //Generate an object array.
    BankAccount account[10];
    int firstAccount = 100;

    //Initialize every account with a number and balance.
    for (int i = 0; i < 10; i++)  {

        account[i] = BankAccount(firstAccount);
        firstAccount++;

    }//end for

    //Continue
    while(com)  {

        int firstMenuSelect;
        int mainMenuSelect;
        //int delta;

        firstMenuSelect = menu1(com);

        if (firstMenuSelect == 1)  {

            cout << "\nWhich account would you like to access?" << endl;
            accountSelect = validate3() - 100;

            bool com2 = true;

            //Continue - Main menu logic.
            while (com2)  {

                mainMenuSelect = menu2();
                int delta;

                //Deposit
                if (mainMenuSelect == 1)  {

                    cout << "\nHow much money would you like to add?" << endl;
                    delta = validate2();

                    balance = account[accountSelect].deposit(delta);

                    cout << "\nNew Balance: " << balance << endl;

                }//end if

                //Withdraw
                else if (mainMenuSelect == 2)  {

                    cout << "\nHow much money would you like to withdraw?" << endl;
                    delta = validate2();

                    balance = account[accountSelect].withdrawal(delta);

                    cout << "\nNew Balance: " << balance << endl;

                }//end else if

                //Get Balance
                else if (mainMenuSelect == 3)  {

                    cout << "\nCurrent Balance: " << account[accountSelect].getBalance() << endl;

                }//end else if

                //Accrue Interest
                else if (mainMenuSelect == 4)  {

                    double interest = 0.05;
                    int years = 5;

                    double balanceAdd = accrue(accountSelect, interest, years, account);
                    account[accountSelect].deposit(balanceAdd);

                    cout << "\nYour new balance after 5 years is: " << account[accountSelect].getBalance() << endl;

                }//end else if

                //Transfer Cash Monies
                else if (mainMenuSelect == 5)  {

                    cout << "\nHow much money would you like to transfer?" << endl;
                    int transfer = validate2();
                    cout << "\nWhich account would you like to transfer the money to?" << endl;
                    int transferAccount = validate2() - 100;

                    account[accountSelect].withdrawal(transfer);
                    account[transferAccount].deposit(transfer);

                    cout << "\nTransaction complete." << endl;

                }//end else if

                //Trip flag, go back to first menu.
                else  {

                    com2 = false;

                }//end else

            }//end while

        }//end if

        //Trip flag, end program.
        else  {

            com = false;

        }//end else

    }//end while

}//end main

/** The first, two selection menu.
* @param com - Boolean value which keeps the menu open.
* @return select - The user's selection. */

int menu1(bool &com)  {

    int menuSize = 2;

    cout << "\nMENU:" << endl;
    cout << "1. Access Account" << endl;
    cout << "2. Quit" << endl;

    int select = validate(menuSize);

    if (select == 2)
        com = false;

    return select;

}//end menu1

/** Validation for menus, dependent on size parameter.
* @param size - The size of the domain over which the user can make a selection.
* @return selection - The user's selection. */

int validate(int size)  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 1 && selection  <= size)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 1 and " << size << "." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 1 and " << size << "." << endl;

        }//end else

    }//end while

    return selection;

}//end validate

/** The second, six part menu.
* @return select - The user's selecion. */

int menu2()  {

    int menuSize = 6;

    cout << "\nMENU:" << endl;
    cout << "1. Deposit Funds" << endl;
    cout << "2. Withdraw Funds" << endl;
    cout << "3. Check Account Balance" << endl;
    cout << "4. Put In Savings" << endl;
    cout << "5. Transfer Funds" << endl;
    cout << "6. Go To Main Menu" << endl;

    int select = validate(menuSize);

    return select;

}//end menu2

/** Validates input that can be any integer.
* @return selection - The user's selection. */

int validate2()  {

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
            cout << "Invalid entry, please enter an integer" << endl;

        }//end else

    }//end while

    return selection;

}//end validate2

/** Input validation with regard to account numbers
* @return selection - The user's account selection. */

int validate3()  {

    bool fail = true;
    int selection;

    while (fail)  {

        if (cin >> selection)  {

            if (selection >= 100 && selection  <= 109)  {

                fail = false;

            }//end if
            else  {

                cout << "Invalid entry, please enter a number between 100 and 109." << endl;

            }//end else

        }//end if
        else  {

            cin.clear();
            string invalid;
            cin >> invalid;
            cout << "Invalid entry, please enter a number between 100 and 109." << endl;

        }//end else

    }//end while

    return selection;

}//end validate3

/** Function which returns the amount of interest accrued.
* @param accountSelect - Which account to access.
* @param interest - The interest rate.
* @param years - Years the interest will build.
* @param account[] - The account array itself.
* @return balanceAdd - Amount to be added to the principle. */

double accrue(int accountSelect, double interest, int years, BankAccount account[])  {

    double balance = account[accountSelect].getBalance();
    double balanceAdd = balance * interest * years;

    return balanceAdd;

}//end accrue
