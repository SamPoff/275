#include <cstdlib>

/** Class which represents a bank account. */
class BankAccount {

private:

    /** balance - The account's balance. */
    double balance;
    /** accountNumber - The account number. */
    int accountNumber;

public:

    /** Sets account number and balance. */
    BankAccountMaker(int accountNumber_0)  {

        accountNumber = accountNumber_0;
        balance = 0;

    }//end BankAccount

    /** Retrieves the account's balance.
    * @param balance - The bank account's balance. */
    double getBalance()  {

        return balance;

    }//end getBalance

    /** Adds a new balance and returns the new value.
    * @param toAdd - Amount to be added to the account.
    * @return balance - The amount of money in the account. */
    double deposit(int toAdd)  {

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
    double withdrawal(int toWithdraw)  {

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
    int accountNum()  {

        return accountNumber;

    }//end accountNum

};//end class
