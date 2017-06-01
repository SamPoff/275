#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

class LinkedList {

    private:

            /** Node struct - defines the nodes. */
            struct Node {
                string value;
                Node *next;
            };//end Node
            Node *first;

            /** Add node.
            @param newNode - the string the user would like to add.
            @param list - the linked list. */
            void add(Node*, Node*);
            /** Add to list at index - overloaded.
            @param s - the string the user would like to add.
            @param index - the index where the user wants to add a node.
            @param count - the current node.
            @param list - the linked list. */
            void add(Node*, int, int, Node*);

            /** Gets value at an index - overloaded.
            @param index - the index the user wants to retrieve.
            @param count - the current node.
            @param list - the linked list.
            @param retString - the string at the specified node.
            @return retString - the value at the specified location. */
            string get(int index, int count, Node *list, string retString);

            /** Remove from list by index - overloaded.
            @param index - the index the user would like to remove.
            @param count - the index of the current node.
            @param list - the linked list.
            @return retString - the character which was removed. */
            string remove(int, int, Node*);
            /** Remove from list by letter - overloaded.
            @param index - the index the user would like to remove.
            @param letter - the letter the user would like to remove.
            @param list - the linked list.
            @return retString - the character which was removed. */
            string remove( string, Node*);

            /** Searches for a given letter - overloaded.
            @param index - the index the user wants to search for.
            @return index - the index of the searched for value. */
            int search(string letter, int index);

            /** Returns size of list - overloaded.
            @param list - the linked list.
            @return size - the size of the list. */
            int size(Node*);

    public:

            /** Linked list default constructor */
            LinkedList() { first = NULL; }
            /** List De-constructor */
            ~LinkedList();

            /** Overloaded output operator.
            @param out - output stream.
            @param list - the linked list.
            @return out - the output stream. */
            friend std::ostream & operator<< (std::ostream & out, LinkedList &list);

            /** Add to list at end.
            @param s - the string the user would like to add. */
            void add(string);
            /** Add to list at index.
            @param s - the string the user would like to add.
            @param index - the index where the user wants to add a node. */
            void add(string, int);

            /** Gets value at an index.
            @param index - the index the user wants to retrieve.
            @return retString - the value at the specified location. */
            string get(int index);

            /** Remove from list by letter.
            @param letter - the letter the user would like to remove. */
            string remove(string);
            /** Remove from list by index.
            @param index - the index the user would like to remove.
            @return retString - the removed character. */
            string remove(int);

            /** Searches for the given character.
            @param letter - the letter the user wants to search for.
            @return result from search overloaded. */
            int search(string letter);

            /** Returns size of list.
            @return size - the size of the list. */
            int size();

            /** Prints the contents of the linked list */
            void print();

};
#endif
