/*
Author: Samuel Poff
Program: inClass4
Description: This program has three functions which perform a task
using recursive logic. One of them adds all the digits of the number
together, the other finds the fibonacci number at a given index, and the
last converts binary to decimal.
*/

#include <iostream>
#include <math.h>

using namespace std;

int addDigits(int num);
int revFibonacci(int f1, int f2, int c, int n);
int binToDec(string bin);

int main() {

    // Copied from BB.

    if(addDigits(321) == 6){

        cout<< "\naddDigits is correct!";

    }//end if

    if(revFibonacci(0,1,1,10) == 55){

        cout << "\nrevFib is correct!";

    }//end if

    if(binToDec("1011101") == 93){

        cout << "\nbinToDec is correct!\n";

    }//end if

    if(addDigits(428) == 14){

        cout<< "\naddDigits is correct!";

    }//end if

    if(revFibonacci(0,1,1,5) == 5){

        cout << "\nrevFib is correct!";

    }//end if

    if(binToDec("1101100") == 108){

        cout << "\nbinToDec is correct!\n";

    }//end if


}//end main

/**Finds the Sum of the digits of num
* @param num value to find the sum of
* @return the sum of the digits
*/

int addDigits(int num)  {

    //Num has to be more than one digit or termination condition is met.
    if (num >= 9)  {

        //num/ten moves the radix one place, num mod ten singles out the last digit.
        return addDigits(num / 10) + num % 10;

    }//end if

    return num;

}//end addDigits

/**Finds the nth Fibonacci value
* @param f1 n-2 Fibonacci value
* @param f2 n-1 Fibonacci value
* @param c  counter
* @param n  the number c should count up to
* @return  the nth Fibonacci value
*/

int revFibonacci(int f1, int f2, int c, int n)  {// f1, f2, count, iterations

    //Terminating condition
    if (c <= n)  {

        //Iterate by adding f1 and g2, and making them the new f2.
        return (revFibonacci((f2), (f1 + f2), c + 1, n));

    }//end if

    return (f1);

}//end revFibonacci

/**Converts a binary string to decimal
* @param bin the binary string
* @return the decimal value
*/

int binToDec(string bin)  {

    //Isolate the first character from the rest.
    string first = bin.substr(0, 1);
    string remaining = bin.substr(1);
    int value;

    //If the first value is zero continue.
    if (first == "0")  {

        value = 0;

    }//end if

    else  {

        value = 1;

    }//end else

    if (bin.length() > 1)  {

        //Add 2^length to binToDec of the remaining values.
        return value * pow(2, bin.length() - 1) + binToDec(remaining);

    }//end if

    return value;

}//end binToDec


