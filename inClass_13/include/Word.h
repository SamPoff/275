#ifndef WORD_H
#define WORD_H
#include "BST.h"
#include <iostream>

using namespace std;

class BST;

class Word {

    private:

        friend ostream & operator<< (ostream & out, Word * myWord);
        friend ostream & operator<< (ostream & out, Word myWord);
        friend class BST;
        friend BST readFromFile();
        string word;
        int    freq;

    public:

        Word();
        Word(string);
        Word(string, int);
        string getWord();
        int getFreq();
        void increment();
        bool operator<  (const Word & aWord);
        bool operator<= (const Word & aWord);
        bool operator== (const Word & aWord);

};

#endif // WORD_H
