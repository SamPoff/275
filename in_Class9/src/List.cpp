#include "List.h"
#include <Square.h>
#include <assert.h>

using namespace std;

/** Adds a square to the linked list.
@param s - the square to add. */
void List::add(Square s) {

    Node *newNode;
    newNode = new Node;
    newNode -> mySquare = s;
    newNode -> next = NULL;
    if (first == NULL) {
        first = newNode;
    }//end if
    else {
        Node *findLast;
        findLast = first;
        while (findLast -> next != NULL) {
            findLast = findLast -> next;
        }//end while
        findLast -> next = newNode;
    }//end else

}//end List

/** Returns size of list
@return count - size of the list. */
int List::size() {

    Node *findLast;
    findLast = first;
    int count = 0;
    while (findLast != NULL) {
        findLast = findLast -> next;
        count++;
    }//end while
    return count;

}//end size

/** Prints the contents of the list. */
void List::print() {

    Node *findLast;
    findLast = first;
    while (findLast != NULL) {
        cout << findLast->mySquare << "";
        findLast = findLast->next;
    }//end while
    cout << endl;

}//end print

/** Deletes list elements */
List::~List() {

    Node *nextNode;
    Node *nodePtr;
    nodePtr = first;
    while (nodePtr != NULL) {
        nextNode = nodePtr -> next;
        delete nodePtr;
        nodePtr = nextNode;
    }//end while

}//end ~List

/** Returns the value at a given index.
@param index - the index the user wants to search for. */
Square List::get(int index) {

    int i = 0;
    struct Node *temp = first;
    for (temp = first; temp != NULL; temp = temp->next) {
        if (i == index) return (temp->mySquare);
        i++;
    }//end for
    assert(0);

}//end get
