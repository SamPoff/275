#include "BankAccount.h"

/** Sets account number and balance. */
BankAccount::BankAccount()  {

     accountNumber = 0;
     balance = 0;

}//end BankAccount

/** Sets account number and balance. */
BankAccount::BankAccount(int accountNumber_0)  {

     accountNumber = accountNumber_0;
     balance = 0;

}//end BankAccount

/** Retrieves the account's balance.
* @param balance - The bank account's balance. */
double BankAccount::getBalance()  {

    return balance;

}//end getBalance

/** Adds a new balance and returns the new value.
* @param toAdd - Amount to be added to the account.
* @return balance - The amount of money in the account. */
double BankAccount::deposit(int toAdd)  {

    if (toAdd > 0)  {

        balance += toAdd;

        return balance;

    }//end if

    else  {

        return balance;

    }//end else

}//end deposit

/** Changes the value of the balance after a withdrawal.
* @param toWithdraw - Amount to be withdrawn.
* @return balance - The new balance after the withdrawal. */
double BankAccount::withdrawal(int toWithdraw)  {

    if (toWithdraw > 0)  {

        balance -= toWithdraw;

        return balance;

    }//end if
    else  {

        return balance;

    }//end else

}//end withdrawal

/** Function which will get the account number.
* @return accountNumber - The account number. */
int BankAccount::accountNum()  {

    return accountNumber;

}//end accountNum


