#include <stddef.h>
#include "fraction.h"
#include "vector.h"

//multiplies the vector b by the scalar and adds the resulting vector to a
void addVector(Fraction a[], Fraction b[], size_t size, Fraction *scalar) {
	Fraction tempFract;

	for (int i = 0; i < size; i++) {
		tempFract.numerator = scalar->numerator;
		tempFract.denominator = scalar->denominator;

		multiplyFraction(&tempFract, &b[i]);
		addFraction(&a[i], &tempFract);
	}
}

//multiplies the vector b by the scalar and subtracts the resulting vector from a
void subVector(Fraction a[], Fraction b[], size_t size, Fraction *scalar) {
	Fraction tempFract;

	for (int i = 0; i < size; i++) {
		tempFract.numerator = scalar->numerator;
		tempFract.denominator = scalar->denominator;

		multiplyFraction(&tempFract, &b[i]);
		subFraction(&a[i], &tempFract);
	}
}

//multiplies each element in the vector a by the scalar
void multiplyVector(Fraction a[], size_t size, Fraction *scalar) {
	for (size_t i = 0; i < size; i++) multiplyFraction(&a[i], scalar);
}

void swapVectors(Fraction vectorA[], Fraction vectorB[], size_t size) {
	for (size_t i = 0; i < size; i++) swapFractions(&vectorA[i], &vectorB[i]);
}

//returns 1 if all the fractions in a vector are equal to 0
int isZeroVector(Fraction a[], size_t size) {
	for (int i = 0; i < size; i++) if (!isZero(&a[i])) return 0;
	return 1;
}
