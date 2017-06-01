#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <Point.h>
using namespace std;

class Stack {

    private:

        struct Node{
            Point value;
            Node * next;
        };
        Node * top;

    public:

        /** Default constructor. */
        Stack(){ top = NULL; }
        /** Deconstructs nodes. */
        ~Stack();

        /** Returns true is stack is empty. */
        bool isEmpty(){ return top == NULL; }
        /** Adds new point to stack.
        @param val - value to be added. */
        void push( Point val );
        /** Removes point from stack
        @return retVal - value at removed stack node. */
        Point pop();
        /** Returns top value from stack but does not remove it. */
        Point peek() { return top->value; }
        /** Returns size of stack.
        @return size - the size of the stack. */
        int size();
        /** Prints the stack */
        void printStack();

};
#endif
