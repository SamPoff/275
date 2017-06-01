#include <LinkedList.h>

using namespace std;

int search(string letter);

int main() {

    LinkedList list;
    list.add("B");
    list.add("D");
    list.add("A", 0);
    list.add("C", 2);
    list.add("E", 4);
    list.add("G", 6); //this shouldn’t do anything

    cout << list <<endl;

    // search seems to work

    cout << list.search( "C" ) << endl;
    cout << list.search( "A" ) << endl;
    cout << list.search( "G" ) << endl; //does not exist

    // remove works for index and 'A', won't remove node for 'B'-'E'.

    cout << list.remove( 1 )   << endl;
    cout << list.remove( "D" ) << endl;
    cout << list.remove( "G" ) << endl; //does not exist

    // size works

    cout << list.size() <<endl;

    // Overloaded output operator works

    cout << list <<endl;

    return 0;

}

