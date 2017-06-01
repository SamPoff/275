#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <Person.h>

using namespace std;

class LinkedList {

    private:
        struct Node {
            Person value;
            Node *next;
        };
        Node *first;

    public:
        LinkedList() {
            first = NULL;
        }
        ~LinkedList();
        bool isEmpty() {
            return first == NULL;
        }
        void add(Person);
        int size();
        void print();
        //ostream & operator<<(ostream & out, Person p);
};
#endif
