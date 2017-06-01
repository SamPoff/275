#include "Person.h"

using namespace std;

bool Person::operator< (const Person & p)  {
    if (lastName != p.lastName)
        return lastName < p.lastName;
    else
        return firstName < p.firstName;
}//end overload<

bool Person::operator> (const Person & p)  {
    if (lastName != p.lastName)
        return lastName > p.lastName;
    else
        return firstName > p.firstName;
}//end overload<

bool Person::operator<= (const Person & p)  {
    if (lastName != p.lastName)
        return lastName < p.lastName;
    else
        return true;
}//end overload<

bool Person::operator>= (const Person & p)  {
    if (lastName != p.lastName)
        return lastName > p.lastName;
    else
        return true;
}//end overload<

bool Person::operator== (const Person & p)  {
    return lastName == p.lastName;
}//end overload<

Person::Person() {

    firstName   = "";
    lastName    = "";
    phoneNumber = "";
    address     = "";
    city        = "";
    zip         = "";
    state       = "";

}//end person

Person::Person(string firstNamea,
               string lastNamea ,
               string phoneNumbera ,
               string addressa  ,
               string citya     ,
               string zipa         ,
               string statea   ){

    firstName   = firstNamea;
    lastName    = lastNamea;
    phoneNumber = phoneNumbera;
    address     = addressa;
    city        = citya;
    zip         = zipa;
    state       = statea;

}//end person

void Person::modFN(string firstNamea) {
    firstName = firstNamea;
}//end modFN

void Person::modLN(string lastNamea) {
    lastName = lastNamea;
}//end modLN

void Person::modPN(int phoneNumbera) {
    phoneNumber = phoneNumbera;
}//end modPN

void Person::modAD(string addressa) {
    address = addressa;
}//end modAD

void Person::modCI(string citya) {
    city = citya;
}//end modCI

void Person::modZI(int zipa) {
    zip = zipa;
}//end modZI

void Person::modST(string statea) {
    state = statea;
}//end modST







