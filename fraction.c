#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fraction.h"

//Uses Euclid's algorithm to find the greatest common denominator between two ints.
int GCD(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

//Sets a to a fractoin based on the string passed in.
//Memory for a must be allocated before passing it to this function.
//str must be in the form of "x/y" or a whole number.
void parseFraction(Fraction *a, char *str) {
	char *divptr = strchr(str, '/');
	a->numerator = atoi(str);
	a->denominator = atoi(divptr + 1);
	reduceFraction(a);
}

//Uses GCD to simplify a fraction.
//If the fraction is 0 or a hole number the denominator is set to 1.
//If the fraction is negative then the numerator will be set to a negative number.
void reduceFraction(Fraction *a) {
	if (a->denominator == 0 || a-> numerator == 0) {
		a->numerator = 0;
		a->denominator = 1;
		return;
	}
	int gcf = GCD(a->numerator, a->denominator);
	a->numerator = a->numerator / gcf;
	a->denominator = a->denominator / gcf;
	if (a->denominator < 0) {
		a->numerator = -(a->numerator);
		a->denominator = -(a->denominator);
	}
}

//Prints the fraction to stdout.
void printFraction(Fraction *a) {
	reduceFraction(a);
	if (a->denominator == 1)
		printf("%d", a->numerator);
	else if (a->denominator == 0 || a->numerator == 0)
		printf("0");
	else
		printf("%d/%d", a->numerator, a->denominator);
}

//Prints the fraction to the output file.
void fprintFraction(Fraction *a, FILE *outfile) {
	reduceFraction(a);
	if (a->denominator == 1)
		fprintf(outfile, "%d", a->numerator);
	else if (a->denominator == 0 || a->numerator == 0)
		fprintf(outfile, "0");
	else
		fprintf(outfile, "%d/%d", a->numerator, a->denominator);
}

//Adds b to a, changing the contents of a.
void addFraction(Fraction *a, Fraction *b) {
	a->numerator = (a->numerator * b->denominator) + (b->numerator * a->denominator);
	a->denominator *= b->denominator;
	reduceFraction(a);
}

//Subtracts b from a, changing the contents of a.
void subFraction(Fraction *a, Fraction *b) {
	a->numerator = (a->numerator * b->denominator) - (b->numerator * a->denominator);
	a->denominator *= b->denominator;
	reduceFraction(a);
}

//Multiplies a by b, changing the contents of a.
void multiplyFraction(Fraction *a, Fraction *b) {
	a->numerator *= b->numerator;
	a->denominator *= b->denominator;
	reduceFraction(a);
}

//Divides a by b, changing the contents of a.
void divideFraction(Fraction *a, Fraction *b) {
	a->numerator *= b->denominator;
	a->denominator *= b->numerator;
	reduceFraction(a);
}

//Swaps the contents of two fractions.
void swapFractions(Fraction *a, Fraction *b) {
	Fraction temp;
	temp.numerator = a->numerator;
	temp.denominator = a->denominator;
	a->numerator = b->numerator;
	a->denominator = b->denominator;
	b->numerator = temp.numerator;
	b->denominator = temp.denominator;
}

//Sets inverse to be the inverse of a.
//The memory for inverse must be allocated before it is passed to this function.
void getInverse(Fraction *a, Fraction *inverse) {
	inverse->numerator = a->denominator;
	inverse->denominator = a->numerator;
	//This used in case the original fraction was 0/1
	reduceFraction(inverse);
}

//Returns a 1 if the fraction is equal to 0 and 0 otherwise.
int isZero(Fraction *a) {
	return a->numerator == 0 || a->denominator == 0;
}

//Returns 1 if the two fractions are equal and 0 otherwise.
int equalsFraction(Fraction *a, Fraction *b) {
	reduceFraction(a);
	reduceFraction(b);
	return a->numerator == b->numerator && a->denominator == b->denominator;
}
