#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <Square.h>

using namespace std;

class List {

    private:

        struct Node {
            Square mySquare;
            Node *next;
        };
        Node *first;

    public:

        /** Default list constructor. */
        List() {
            first = NULL;
        }
        /** Deletes list elements */
        ~List();
        /** Returns true if empty, false otherwise.
        @return bool - true or false depending on if condition is met. */
        bool isEmpty() {
            return first == NULL;
        }
        /** Adds a square to the linked list.
        @param s - the square to add. */
        void add(Square s);
        /** Returns size of list
        @return count - size of the list. */
        int size();
        /** Prints the contents of the list. */
        void print();
        /** Returns the value at a given index.
        @param index - the index the user wants to search for. */
        Square get(int index);

};

#endif  // LIST_H
