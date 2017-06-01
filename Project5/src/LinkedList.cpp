#include <LinkedList.h>
#include <Person.h>
#include <iostream>

using namespace std;

void LinkedList::add(Person s) {
    cout << "In" << endl;
    Node *newNode;
    newNode = new Node;
    newNode->value = s;
    newNode->next = NULL;
    if( first == NULL ) {
        cout << "NewNode becomes first." << endl;
        first = newNode;
    }
    else {
        cout << "Step into major else." << endl;
        Node * findSpot;
        findSpot = first;
        bool flag = false;

        if (findSpot->next == NULL) {
            cout << "Findspot next = null" << endl;
            if (newNode->value > findSpot->value) {
                cout << "Choose if." << endl;
                newNode->next = NULL;
                findSpot->next = newNode;
                flag = true;
            }
            else if (newNode->value < findSpot->value) {
                cout << "Choose else if." << endl;
                first = newNode;
                newNode->next = findSpot;
                flag = true;
            }

        }

        if (first->next->next == NULL && !flag) {
            cout << "Inside" << endl;

            if (newNode->value < findSpot->value) {
                cout << "inif" << endl;
                first = newNode;
                newNode->next = findSpot;
            }
            else if (newNode->value > findSpot->value && newNode->value < findSpot->next->value) {
                cout << "inelseif" << endl;
                Node *temp;
                temp = findSpot;
                findSpot->next = newNode;
                newNode->next = temp->next;
            }
            else {
                cout << "in else" << endl;
                newNode->next = NULL;
                findSpot->next->next = newNode;
            }

        }

        while (findSpot->next->next != NULL) {
            if (newNode->value > findSpot->next->value && newNode->value < findSpot->next->next->value) {
                newNode->next = findSpot->next->next;
                findSpot->next->next = newNode;
            }
            findSpot = findSpot->next;
        }
    }
    cout << "Through" << endl;
}

int LinkedList::size() {
    Node *findLast;
    findLast = first;
    int count = 0;
    while( findLast != NULL ) {
        findLast = findLast->next;
        count++;
    }
    return count;
}

void LinkedList::print() {
    Node *findLast;
    findLast = first;
    while( findLast != NULL ) {
        cout << findLast->value << " " << endl;
        findLast = findLast->next;
    }
    cout<< endl;
}

LinkedList::~LinkedList() {
    Node *nextNode;
    Node *nodePtr;
    nodePtr = first;
    while( nodePtr != NULL ) {
        nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
    }
}


