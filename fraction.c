#include "fraction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

void parseFraction(Fraction *a, char *str) {
	char *divptr = strchr(str, '/');
	a->numerator = atoi(str);
	a->denominator = atoi(divptr + 1);
	reduceFraction(a);
}

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

void printFraction(Fraction *a) {
	reduceFraction(a);
	if (a->denominator == 1)
		printf("%d", a->numerator);
	else if (a->denominator == 0 || a->numerator == 0)
		printf("0");
	else
		printf("%d/%d", a->numerator, a->denominator);
}

/*Fraction addFractions(Fraction *a, Fraction *b) {
	Fraction ans;
	ans.numerator = (a->numerator * b->denominator) + (b->numerator * a->denominator);
	ans.denominator = a->denominator * b->denominator;
	reduceFraction(&ans);
	return ans;
}*/

void addFraction(Fraction *a, Fraction *b) {
	a->numerator = (a->numerator * b->denominator) + (b->numerator * a->denominator);
	a->denominator *= b->denominator;
	reduceFraction(a);
}

void subFraction(Fraction *a, Fraction *b) {
	a->numerator = (a->numerator * b->denominator) - (b->numerator * a->denominator);
	a->denominator *= b->denominator;
	reduceFraction(a);
}

void multiplyFraction(Fraction *a, Fraction *b) {
	a->numerator *= b->numerator;
	a->denominator *= b->denominator;
	reduceFraction(a);
}

void divideFraction(Fraction *a, Fraction *b) {
	a->numerator *= b->denominator;
	a->denominator *= b->numerator;
	reduceFraction(a);
}

void swapFractions(Fraction *a, Fraction *b) {
	Fraction temp;
	temp.numerator = a->numerator;
	temp.denominator = a->denominator;
	a->numerator = b->numerator;
	a->denominator = b->denominator;
	b->numerator = temp.numerator;
	b->denominator = temp.denominator;
}

void getInverse(Fraction *a, Fraction *inverse) {
	inverse->numerator = a->denominator;
	inverse->denominator = a->numerator;
	//This used in case the original fraction was 0/1
	reduceFraction(inverse);
}

int isZero(Fraction *a) {
	return a->numerator == 0 || a->denominator == 0;
}

int equalsFraction(Fraction *a, Fraction *b) {
	reduceFraction(a);
	reduceFraction(b);
	return a->numerator == b->numerator && a->denominator == b->denominator;
}
