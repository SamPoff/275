#ifndef BST_H
#define BST_H
#include <iostream>
#include "Word.h"

using namespace std;

class Word;

class BST {

    private:

        friend class Word;
        friend BST readFromFile();
        friend ostream & operator<< (ostream & out, BST tree);
        struct Node {
            Word *value;
            Node *left;
            Node *right;
        }click;
        Node *root;
        void add( Node *&, Node *& );
        void print( Node * );
        void clear( Node * );

    public:

        BST() {
            root = NULL;
        }
        ~BST( ) {
            clear( root );
        }
        bool isEmpty() {
            return root == NULL;
        }
        void add( Word );
        void print();
        void clear( ){
            clear( root );
        }

};

#endif
