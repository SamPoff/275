#include "Stack.h"

/** Overloaded output operator; enables a formatted output for
    Fraction objects.
    @param mySong - explicit parameter.
    @return out - the io stream with the desired output. */
std::ostream & operator<< (std::ostream & out, Point getToThe)  {

    out << "(" << getToThe.getX()  << ", " << getToThe.getY() << ")" << endl;

    return out;

}//end ostream

/** Adds new point to stack.
@param val - value to be added. */
void Stack::push( Point val ) {

    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = top;
    top = newNode;
}

/** Removes point from stack
@return retVal - value at removed stack node. */
Point Stack::pop() {

    Point retVal;
    if( top != NULL ){
        retVal = top->value;
        Node *temp = top->next;
        delete top;
        top = temp;
    }return retVal;
}

/** Returns size of stack.
@return size - the size of the stack. */
int Stack::size() {

    int size = 0;
    Node *findLast = top;
    while( findLast != NULL){
        findLast = findLast->next;
        size++;
    }
    return size;

}

/** Prints the stack */
void Stack::printStack() {

    Node *findLast = top;
    while(findLast != NULL ){
        cout << findLast->value << " ";
        findLast = findLast->next;
    }
    cout<<endl;
}

/** Deconstructs nodes. */
Stack::~Stack() {

    Node *nextNode;
    Node *nodePtr = top;
    while(nodePtr != NULL) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }

}
