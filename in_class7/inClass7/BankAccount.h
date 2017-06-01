#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount  {

private:

    /** balance - The account's balance. */
    double balance;
    /** accountNumber - The account number. */
    int accountNumber;

public:

    /** Sets account number and balance. */
    BankAccountMaker(int accountNumber_0);
    /** Retrieves the account's balance.
    * @param balance - The bank account's balance. */
    double getBalance();
    /** Adds a new balance and returns the new value.
    * @param toAdd - Amount to be added to the account.
    * @return balance - The amount of money in the account. */
    double deposit(int toAdd);
    /** Changes the value of the balance after a withdrawal.
    * @param toWithdraw - Amount to be withdrawn.
    * @return balance - The new balance after the withdrawal. */
    double withdrawal(int toWithdraw);
    /** Function which will get the account number.
    * @return accountNumber - The account number. */
    int accountNum();

};//end class

#endif // BANKACCOUNT_H
