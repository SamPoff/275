#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person {

    private:
        string firstName   ;
        string lastName    ;
        string phoneNumber ;
        string address     ;
        string city        ;
        string zip         ;
        string state       ;
        friend class LinkedList;

    public:
        Person();
        Person(string firstNamea   ,
               string lastNamea    ,
               string phoneNumbera ,
               string addressa     ,
               string citya        ,
               string zipa         ,
               string statea      );
        void modFN(string firstNamea);
        void modLN(string lastNamea);
        void modPN(int phoneNumbera);
        void modAD(string addressa);
        void modCI(string citya);
        void modZI(int zipa);
        void modST(string streeta);
        string retFN() {return firstName;}
        string retLN() {return lastName;}
        string retPN() {return phoneNumber;}
        string retAD() {return address;}
        string retCI() {return city;}
        string retZI() {return zip;}
        string retST() {return state;}
        bool operator<(const Person & p);
        bool operator>(const Person & p);
        bool operator<= (const Person & p);
        bool operator>= (const Person & p);
        bool operator== (const Person & p);

};

ostream & operator<<(ostream & out, Person & p);

#endif // PERSON_H
