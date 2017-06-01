#include <iostream>

using namespace std;

/** Finds the minimum value in an array
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @param i iterator
* @param max minimum value found so far
* @return minimum value
*/

int minArray(int array[], int size, int i, int min[]) {

    if (array[i] < array[size - 1])  {

        min[0] = array[i];
        minArray(array, size - 1, i, min);

    }//end if

    if (array[i] > array[size - 1])  {

        min[0] = array[size - 1];
        minArray(array, size, i + 1, min);

    }//end else if

	return min[0];

}//minArray

/** Facade function which passes 'hidden variables' to minArray
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @return minimum value
*/

int findMin(int array[], int size)  {

    int i = 0;
    int min[] = {0};

    min[0] = minArray(array, size, i, min);

    return min[0];

}//end findMin

/** Finds the maximum value in an array
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @param i iterator
* @param max maximum value found so far
* @return maximum value
*/

int maxArray(int array[], int size, int i, int max[]) {

    if (array[i] > array[size - 1])  {

        max[0] = array[i];
        maxArray(array, size - 1, i, max);

    }//end if

    if (array[i] < array[size - 1])  {

        max[0] = array[size - 1];
        maxArray(array, size, i + 1, max);

    }//end else if

	return max[0];

}//maxArray

/** Facade function which passes 'hidden variables' to maxArray
* @param array array of values (sorted or unsorted)
* @param size length of the array
* @return maximum value
*/

int findMax(int array[], int size)  {

    int i = 0;
    int max[] = {0};

    max[0] = maxArray(array, size, i, max);

    return max[0];

}//end findMax

/** Reverses a string
* @param s the string to reverse
* @return the reversed string
*/

string reverseStr(string s) {

    if (s.length() > 1)  {

        return reverseStr(s.substr(1, s.length())) + s.at(0);

    }//end if
    else  {

        return s;

    }//end else

}

/** Returns the number of times c appears in the string str
* @param str string to test
* @param c character to find
* @return number of times the character appeared in the string
*/

int charFrequency(string str, char c) {

    int i = 0;
    i = str.find(c, i);

    if (i > str.length())  {

            return 0;

    }//end if

    else  {

        i++;
        return 1 + charFrequency(str.substr(i), c);

    }//end else

}//end charFrequency

int main() {

    int array [] = {46, 22, 7, 58, 91, 55, 31, 84, 12, 78};

    if(findMax(array, 10) == 91) {

        cout<< "findMax is correct!" << endl;

    }//end if

    if(findMin(array, 10) == 7) {

        cout<< "findMin is correct!" << endl;

    }//end if

    if(reverseStr("Hello") == "olleH") {

        cout<< "reverseString is correct!" << endl;

    }//end if

    if(charFrequency("antidisestablishmentarianism",'i') == 5) {

        cout<< "charFrequency is correct!" << endl;

    }//end if
        if(reverseStr("pupils") == "slipup") {

        cout<< "reverseString is correct!" << endl;

    }//end if

    if(charFrequency("antidisestablishmentarianism",'a') == 4) {

        cout<< "charFrequency is correct!" << endl;

    }//end if


}//end main

