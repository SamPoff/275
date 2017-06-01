#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>

class Fraction  {

private:

    /** numerator - the top number in the fraction. */
    int numerator;
    /** denominator - the bottom number of the fraction. */
    int denominator;

public:

    /** Overloaded output operator; enables a formatted output for
    Fraction objects.
    @return out - the io stream with the desired output. */
    friend std::ostream  &operator<< (std::ostream &out, Fraction myFrac);
    /** Overloaded input operator; allows user inputs to be assigned
    to specific class traits in one call.
    @return in - the input stream with the user's values. */
    friend std::istream  &operator>> (std::istream &in, Fraction &myFrac);
    /** Overloaded 'plus' operator; allows Fraction objects
    to be added together with a single call.
    @param frac1 - the first fraction.
    @param frac2 - the second fraction.
    @return newFrac - The sum of the first two fractions */
    Fraction operator+ (const Fraction &frac2);
    /** Overloaded 'minus' operator; allows Fraction objects
    to be subtracted from one another with a single call.
    @param frac1 - the first fraction.
    @param frac2 - the second fraction.
    @return newFrac - The sum of the first two fractions */
    Fraction operator- (const Fraction &frac2);
    /** Overloaded multiplication operator; allows Fraction
    objects to be multiplied with a single call.
    @param frac1 - the first fraction.
    @param frac2 - the second fraction.
    @return newFrac - The sum of the first two fractions */
    Fraction operator* (const Fraction &frac2);
    /** Overloaded division operator; allows Fraction objects
    to be divided with a single call.
    @param frac1 - the first fraction.
    @param frac2 - the second fraction.
    @return newFrac - The sum of the first two fractions */
    Fraction operator/ (const Fraction &frac2);
    /** Default constructor with no values. */
    Fraction();
    /** Takes in the numerator and denominator and will reset
    *   the denominator to one if it is sent a zero. */
    Fraction(int num, int den);

};//end class

#endif // FRACTION_H_INCLUDED
