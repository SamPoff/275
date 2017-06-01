#include <Square.h>
#include <List.h>
#include <iostream>

using namespace std;

/** Lets the user know if the list is empty, if
    not it will output the size.
    @param list - the linked list. */
void printIsEmpty(List & list) {

    if(list.isEmpty()) {

        cout<< "List is empty." <<endl;

    }//end if
    else {

        cout << "List is not empty."     <<endl;
        cout << "Size = " << list.size() <<endl;

    }//end else
}//end printIsEmpty

/** Main */
int main() {

    List list;
    printIsEmpty(list);

    Square s1(1,2,3,4);
    Square s2(2,3,4,5);
    Square s3(3,4,5,6);
    Square s4(4,5,6,7);

    list.add(s1);
    list.add(s2);
    list.add(s3);
    list.add(s4);

    printIsEmpty( list );
    list.print();

    cout << "The first item in the list is: " << list.get(0) << endl;
    cout << "The third item in the list is: " << list.get(2) << endl;

    return 0;

}//end main
