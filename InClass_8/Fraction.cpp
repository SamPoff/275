#include "Fraction.h"
#include <iostream>

std::ostream  &operator<< (std::ostream &out, Fraction myFrac);
std::istream  &operator>> (std::istream &in, Fraction &myFrac);

/** Default constructor; constructs a Fraction object
    with a set numerator and denominator. */
Fraction::Fraction()  {

    numerator = 0;
    denominator = 1;

}//end fraction

/** Fraction constructor which allows the user to
    pass in a desired numerator and denominator. */
Fraction::Fraction(int num, int den)  {

    if (denominator == 0)  {
        denominator = 1;
        numerator = num;
    }//end if

    else  {
        numerator = num;
        denominator = den;
    }//end else

}//end fraction

/** Overloaded 'plus' operator; allows Fraction objects
    to be added together with a single call.
    @param frac2 - the second fraction.
    @return temp - The sum of the first two fractions */
Fraction Fraction::operator+ (const Fraction & frac2)  {

    Fraction temp;

    if (denominator > frac2.denominator) {
		temp.denominator = denominator * frac2.denominator;
		temp.numerator = (frac2.numerator * denominator) + (numerator * frac2.denominator);
	}
	else if (denominator < frac2.denominator) {
		temp.denominator = denominator * frac2.denominator;
		temp.numerator = (numerator * frac2.denominator) + (denominator * frac2.numerator);
	}
	else {
		temp.numerator = numerator + frac2.numerator;
		temp.denominator = denominator;
	}

	return temp;

}//end operator+

/** Overloaded 'minus' operator; allows Fraction objects
    to be subtracted from one another with a single call.
    @param frac2 - the second fraction.
    @return temp - The sum of the first two fractions */
Fraction Fraction::operator- (const Fraction & frac2)  {

	Fraction temp;

	if (denominator > frac2.denominator) {
		temp.denominator = denominator * frac2.denominator;
		temp.numerator = (numerator * frac2.denominator) - (frac2.numerator * denominator);
	}
	else if (denominator < frac2.denominator) {
		temp.denominator = denominator * frac2.denominator;
		temp.numerator = (denominator * frac2.numerator) - (numerator * frac2.denominator);
	}
	else {
		temp.numerator = numerator - frac2.numerator;
		temp.denominator = denominator;
	}

	return temp;

}//end operator-

/** Overloaded multiplication operator; allows Fraction
    objects to be multiplied with a single call.
    @param frac2 - the second fraction.
    @return temp - The sum of the first two fractions */
Fraction Fraction::operator* (const Fraction & frac2)  {

	Fraction temp;

    temp.numerator = numerator * frac2.numerator;
    temp.denominator = denominator * frac2.denominator;

	return temp;

}//end operator*

/** Overloaded division operator; allows Fraction objects
    to be divided with a single call.
    @param frac2 - the second fraction.
    @return temp - The sum of the first two fractions */
Fraction Fraction::operator/ (const Fraction & frac2)  {

	Fraction temp;

	temp.numerator = numerator * frac2.denominator;
	temp.denominator = denominator * frac2.numerator;

	return temp;

}//end operator/
