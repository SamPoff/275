#include <LinkedList.h>
#include <assert.h>

using namespace std;

/** List Deconstructor */
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
/** Remove from list by index.
@param index - the index the user would like to remove. */
string LinkedList::remove( int index ) {

    string retString;
    if( first != NULL ) {
        if( index >= 0 && index < size() ) {
            if( index == 0 ) {
                retString = first->value;
                Node *temp = first->next;
                delete first;
                first = temp;
            } else {
                retString = remove( index, 0, first );
            }
        }
    }
    return retString;

}
/** Remove from list by index - overloaded.
@param index - the index the user would like to remove.
@param count - the index of the current node.
@param list - the linked list.
@return retString - the character which was removed. */
string LinkedList::remove( int index, int count, Node *list ) {

    if( count < index - 1 ) {
        return remove( index, count+1, list->next );
    } else {
        Node *delNode = list->next;
        string retString = delNode->value;
        list->next = delNode->next;
        delete delNode;
        return retString;
    }

}
/** Remove from list by letter.
@param letter - the letter the user would like to remove. */
string LinkedList::remove( string letter ) {

    string retString;
    if( first != NULL ) {
        if (first->value == letter) {
            retString = first->value;
            Node *temp = first->next;
            delete first;
            first = temp;
        }
        else {
            return remove( letter, first );
        }
    }
    return retString;
}
/** Remove from list by letter - overloaded.
@param index - the index the user would like to remove.
@param letter - the letter the user would like to remove.
@param list - the linked list.
@return retString - the character which was removed. */
string LinkedList::remove( string letter, Node *list ) {

    string retString = "This is an empty string.";
    if (list != NULL) {
        if(list->next == NULL) {
            return retString;
        }
        else {
            if( list->next->value == letter) {
                retString = list->next->value;
                Node * temp = list->next;
                list->next = temp->next;
                delete temp;
            }
            else {
                retString = remove( letter, list->next );
            }
        }
    }
    return retString;
}
/** Add to list at end.
@param s - the string the user would like to add. */
void LinkedList::add( string s ) {

    Node *newNode = new Node;
    newNode->value = s;
    newNode->next = NULL;
    if( first == NULL ) {
        first = newNode;
    } else {
        add( newNode, first );
    }

}
/** Add node.
@param newNode - the string the user would like to add.
@param list - the linked list. */
void LinkedList::add( Node *newNode, Node *list ) {

    if( list->next == NULL ) {
        list->next = newNode;
    } else {
        add( newNode, list->next );
    }

}
/** Add to list at index.
@param s - the string the user would like to add.
@param index - the index where the user wants to add a node. */
void LinkedList::add( string s, int index ) {

    if( index >= 0 && index <= size() ) {
        Node *newNode = new Node;
        newNode->value = s;
        newNode->next = NULL;
        if( index == 0 ) {
            newNode->next = first;
            first = newNode;
        } else {
            add( newNode, index, 0, first );
        }
    }

}
/** Add to list at index - overloaded.
@param s - the string the user would like to add.
@param index - the index where the user wants to add a node.
@param count - the current node.
@param list - the linked list. */
void LinkedList::add( Node *newNode, int index, int count, Node *list ) {

    if( count < index - 1 ) {
        add( newNode, index, count+1, list->next );
    } else {
        newNode->next = list->next;
        list->next = newNode;
    }

}
/** Returns size of list.
@return size - the size of the list. */
int LinkedList::size() {

    return size(first);

}
/** Returns size of list - overloaded.
@return size - the size of the list. */
int LinkedList::size( Node *list ) {

    if( list == NULL ) {
        return 0;
    } else {
        return size( list->next ) + 1;
    }

}
/** Overloaded output operator.
@param out - output stream.
@param list - the linked list.
@return out - the output stream. */
std::ostream & operator<< (std::ostream & out, LinkedList & list) {

    out << list.get(0) << endl;
    return out;

}//end operator<<
/** Gets value at an index.
@param index - the index the user wants to retrieve.
@return retString - the value at the specified location. */
string LinkedList::get( int index ) {

    string retString = "";
    if(index >= 0 && index < size()) {
        retString = get( index, 0, first, retString);
    }
    return retString;

}
/** Gets value at an index - overloaded.
@param index - the index the user wants to retrieve.
@param count - the current node.
@param list - the linked list.
@param retString - the string at the specified node.
@return retString - the value at the specified location. */
string LinkedList::get( int index, int count, Node *list, string retString ) {

    if( count < size() ) {
        retString = list->value;
        //cout << "index: " << index << " count: " << count << " retString: " << retString << " ";
        return retString + " " + get( index, count+1, list->next, retString );
    } else {
        return "";
    }

}
/** Searches for the given character.
@param letter - the letter the user wants to search for.
@return result from search overloaded. */
int LinkedList::search(string letter) {

    int i = 0;
    return search(letter, i);

}//end get
/** Searches for a given letter - overloaded.
@param index - the index the user wants to search for.
@return index - the index of the searched for value. */
int LinkedList::search(string letter, int index) {

    struct Node *temp = first;
    for (temp = first; temp != NULL; temp = temp->next) {
        if (temp->value == letter) return (index);
        index++;
    }//end for
    return -1;
    assert(0);

}//end get
/** Prints the contents of the linked list */
void LinkedList::print() {

    Node *findLast;
    findLast = first;
    while( findLast != NULL ) {
        cout<< findLast->value << " ";
        findLast = findLast->next;
    }
    cout<< endl;

}
