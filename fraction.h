#ifndef FRACTTION_H
#define FRACTION_H

#include <stdio.h>

typedef struct {
	int numerator;
	int denominator;
} Fraction;

//Uses Euclid's algorithm to find the greatest common denominator between two ints.
int GCD(int a, int b);
//Sets a to a fractoin based on the string passed in.
//Memory for a must be allocated before passing it to this function.
//str must be in the form of "x/y" or a whole number.
void parseFraction(Fraction *a, char *str);
//Uses GCD to simplify a fraction.
//If the fraction is 0 or a hole number the denominator is set to 1.
//If the fraction is negative then the numerator will be set to a negative number.
void reduceFraction(Fraction *a);
//Prints the fraction to stdout.
void printFraction(Fraction *a);
//Prints the fraction to the output file.
void fprintFraction(Fraction *a, FILE *outfile);
//Adds b to a, changing the contents of a.
void addFraction(Fraction *a, Fraction *b);
//Subtracts b from a, changing the contents of a.
void subFraction(Fraction *a, Fraction *b);
//Multiplies a by b, changing the contents of a.
void multiplyFraction(Fraction *a, Fraction *b);
//Divides a by b, changing the contents of a.
void divideFraction(Fraction *a, Fraction *b);
//Swaps the contents of two fractions.
void swapFractions(Fraction *a, Fraction *b);
//Sets inverse to be the inverse of a.
//The memory for inverse must be allocated before it is passed to this function.
void getInverse(Fraction *a, Fraction *inverse);
//Returns a 1 if the fraction is equal to 0 and 0 otherwise.
int isZero(Fraction *a);
//Returns 1 if the two fractions are equal and 0 otherwise.
int equalsFraction(Fraction *a, Fraction *b);

#endif //FRACTION_H
