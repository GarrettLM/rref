#ifndef FRACTTION_H
#define FRACTION_H

typedef struct {
	int numerator;
	int denominator;
} Fraction;

int GCD(int a, int b);
void parseFraction(Fraction *a, char *str);
void reduceFraction(Fraction *a);
void printFraction(Fraction *a);
void addFraction(Fraction *a, Fraction *b);
void subFraction(Fraction *a, Fraction *b);
void multiplyFraction(Fraction *a, Fraction *b);
void divideFraction(Fraction *a, Fraction *b);
void swapFractions(Fraction *a, Fraction *b);
void getInverse(Fraction *a, Fraction *inverse);
int isZero(Fraction *a);
int equalsFraction(Fraction *a, Fraction *b);

#endif
