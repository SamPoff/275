#include "Word.h"
#include "BST.h"

Word::Word() {
    word = "";
    freq = 1;
}

Word::Word(string input) {
    word = input;
    freq = 1;
}

Word::Word(string input, int amount) {
    word = input;
    freq = amount;
}

string Word::getWord() {
    return word;
}

int Word::getFreq() {
    return freq;
}

void Word::increment() {
    freq += 1;
}

/*
ostream & operator<< (ostream & out, Word * myWord)  {

    out << "Word : " << myWord->word << "\n" << "Freq : " << myWord->freq << endl;

    return out;

}//end ostream
*/

bool Word::operator<  (const Word & aWord)  {

    return (word < aWord.word);

}//end operator<

bool Word::operator<=  (const Word & aWord)  {

    return (word <= aWord.word);

}//end operator<

bool Word::operator== (const Word & aWord)  {

    return (word == aWord.word);

}//end operator==
